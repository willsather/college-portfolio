using FontAwesome.Sharp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace COVID_Dashboard
{
    public partial class FormMain : Form
    {

        // Private variables for methods
        private IconButton currentButton;
        private Panel leftBorderButton;
        private Form currentChildForm;


        public FormMain()
        {
            InitializeComponent();

            leftBorderButton = new Panel();
            leftBorderButton.Size = new Size(10, 86);
            panelMenu.Controls.Add(leftBorderButton);
            ActivateButton(IconDashboard);

            // Open application to default Dashboard
            OpenChildForm(new Loading_Form());
            OpenChildForm(new Dashboard_Form());

            this.Text = string.Empty;
            this.ControlBox = false;
            this.DoubleBuffered = true;

            this.MaximizedBounds = Screen.FromHandle(this.Handle).WorkingArea;

            
        }

        private void FormMain_Load(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// Activates Sidebar button (changes state to active)
        /// </summary>
        /// <param name="senderButton"></param>
        private void ActivateButton(object senderButton)
        {
            if (senderButton != null)
            {
                DisableButton();

                // Button
                currentButton = (IconButton)senderButton;
                currentButton.ForeColor = Color.DarkRed;
                currentButton.IconColor = Color.DarkRed;

                currentButton.TextAlign = ContentAlignment.MiddleCenter;
                currentButton.ImageAlign = ContentAlignment.MiddleCenter;

                // Color Panel
                leftBorderButton.BackColor = Color.DarkRed;
                leftBorderButton.Location = new Point(0, currentButton.Location.Y);
                leftBorderButton.Visible = true;
                leftBorderButton.BringToFront();

                // Title Information
                IconTitleBox.IconChar = currentButton.IconChar;
                titleLabel.Text = currentButton.Text;

            }
        }
        /// <summary>
        /// Disables the current sidebar button
        /// </summary>
        private void DisableButton()
        {
            if (currentButton != null)
            {
                // Button
                currentButton.ForeColor = Color.WhiteSmoke;
                currentButton.IconColor = Color.WhiteSmoke;
                currentButton.TextAlign = ContentAlignment.MiddleLeft;
                currentButton.ImageAlign = ContentAlignment.MiddleLeft;

            }
        }

        /// <summary>
        /// Resets the sidebar back to default.
        /// (Do this when logo is clicked)
        /// </summary>
        private void Reset()
        {
            ActivateButton(IconDashboard);
            OpenChildForm(new Dashboard_Form());
        }

        /// <summary>
        /// Opens up each individual child form
        /// to hide previous page and create new
        /// instance of specified child form
        /// </summary>
        /// <param name="child"></param>
        private void OpenChildForm(Form child)
        {
            if (currentChildForm != null)
            {
                currentChildForm.Close();
            }
            currentChildForm = child;
            currentChildForm.TopLevel = false;
            currentChildForm.FormBorderStyle = FormBorderStyle.None;
            currentChildForm.Dock = DockStyle.Fill;

            panelDesktop.Controls.Add(currentChildForm);
            panelDesktop.Tag = currentChildForm;
            currentChildForm.BringToFront();
            currentChildForm.Show();
        }

        // Sidebar Button Click Methods
        ///////////////////////////////
        
        private void IconDashboard_Click(object sender, EventArgs e)
        {
            ActivateButton(sender);
            OpenChildForm(new Loading_Form());
            OpenChildForm(new Dashboard_Form());
        }


        private void IconAbout_Click(object sender, EventArgs e)
        {
            ActivateButton(sender);
            OpenChildForm(new About_Form());
        }

        private void IconSymptoms_Click(object sender, EventArgs e)
        {
            ActivateButton(sender);
            OpenChildForm(new Symptoms_Form());
        }

        private void IconResources_Click(object sender, EventArgs e)
        {
            ActivateButton(sender);
            OpenChildForm(new Loading_Form());
            OpenChildForm(new Resources_Form());
        }

        private void pictureBoxLogo_Click(object sender, EventArgs e)
        {
            Reset();
        }

        // Drag Title Screen to move around
        // (Imports System.Runtime.InteropServices)
        //////////////////////////////
        [DllImport("user32.DLL", EntryPoint = "ReleaseCapture")]
        private extern static void ReleaseCapture();

        [DllImport("user32.DLL", EntryPoint = "SendMessage")]
        private extern static void SendMessage(System.IntPtr hWnd, int wMsg, int wParam, int lParam);

        private void panelTitle_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }


        // Window Close/Minimize/Maximize Buttons
        /////////////////////////////////////////

        private void titleClose_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void titleZoom_Click(object sender, EventArgs e)
        {
            if (WindowState == FormWindowState.Normal)
                WindowState = FormWindowState.Maximized;
            else
                WindowState = FormWindowState.Normal;
        }

        private void titleMinimize_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;
        }


    }
}
