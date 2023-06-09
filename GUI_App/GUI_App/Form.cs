using System;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace GUI_App
{
    public partial class Form : System.Windows.Forms.Form
    {
        private SerialPort _serialPort;
        private DateTime _chartStartingTime;
        private byte[] _serialData;
        int _serialDataPosition;
        private const string _FORMAT = "R{0:00.0}\r";
        public Form()
        {
            InitializeComponent();
            InitializeData();
            var currentTime = DateTime.Now;
            while ((DateTime.Now - currentTime).TotalSeconds < 1) ;
            
        }
        private void InitializeData()
        {
            portNameComboBox.DataSource = SerialPort.GetPortNames();
            _chartStartingTime = DateTime.Now;
            _serialData = new byte[64];
            _serialDataPosition = 0;
        }
        private bool Connect(string portName)
        {
            _serialPort = new SerialPort(portName, 19_200, Parity.None, 8, StopBits.One);
            _serialPort.DataReceived += new SerialDataReceivedEventHandler(SerialPort_DataReceived);
            _serialPort.Open();
            _serialPort.DiscardOutBuffer();
            _serialPort.DiscardInBuffer();

            return true;
        }
        private void Disconnect()
        {
            _serialPort.Close();
        }
        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            if (InvokeRequired)
            {
                BeginInvoke(new EventHandler<SerialDataReceivedEventArgs>(SerialPort_DataReceived), new object[] { sender, e });
                return;
            }
            var passedTime = DateTime.Now - _chartStartingTime;
            var dataLength = _serialPort.BytesToRead;
            var dataBytes = new byte[dataLength];
            var dataRead = _serialPort.Read(dataBytes, 0, dataLength);
            if (dataRead == 0)
            {
                return;
            }
            Array.Copy(dataBytes, 0, _serialData, _serialDataPosition, dataRead);
            _serialDataPosition += dataRead;
            //if (Array.IndexOf(_serialData, 13) != -1 && dataBytes[dataRead - 1] != 13)
            //{
                
            //}

            if (dataBytes[dataRead-1] != 13)
            {
                return;
            }

            _serialDataPosition = 0;

            var dataString = Encoding.ASCII.GetString(_serialData);
            outputTextBox.AppendText(dataString);
            outputTextBox.ScrollToCaret();
            var match = Regex.Match(dataString, @"([-+]?[0-9]*\.?[0-9]+)");
            
            if (match.Success)
            {
                var number = Convert.ToDouble(match.Groups[1].Value);
                distanceChart.Series[0].Points.AddXY(passedTime.TotalSeconds, number);
            }


        }
        private void ConnectButton_Click(object sender, EventArgs e)
        {
            if (portNameComboBox.SelectedIndex == -1)
            {
                return;
            }
            if (!(portNameComboBox.SelectedItem is string portName))
            {
                return;
            }
            if (!Connect(portName))
            {
                return;
            }

            connectButton.Enabled = false;
            portNameComboBox.Enabled = false;
            disconnectButton.Enabled = true;
            sendButton.Enabled = true;
        }
        private void DisconnectButton_Click(object sender, EventArgs e)
        {
            Disconnect();
            disconnectButton.Enabled = false;
            sendButton.Enabled = false;
            connectButton.Enabled = true;
            portNameComboBox.Enabled = true;
        }
        private void SendButton_Click(object sender, EventArgs e)
        {
            if (_serialPort is null)
            {
                return;
            }

            var formatted = string.Format(_FORMAT, Double.Parse(inputTextBox.Text));
            _serialPort.Write(formatted);
            inputTextBox.Clear();
        }
        private void ClearButton_Click(object sender, EventArgs e)
        {
            _chartStartingTime = DateTime.Now;
            distanceChart.Series[0].Points.Clear();
            outputTextBox.Clear();
            outputTextBox.ScrollToCaret();
        }
    }
}
