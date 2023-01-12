namespace COVID_Dashboard
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.panelMenu = new System.Windows.Forms.Panel();
            this.IconAbout = new FontAwesome.Sharp.IconButton();
            this.IconResources = new FontAwesome.Sharp.IconButton();
            this.IconSymptoms = new FontAwesome.Sharp.IconButton();
            this.IconDashboard = new FontAwesome.Sharp.IconButton();
            this.panelLogo = new System.Windows.Forms.Panel();
            this.pictureBoxLogo = new System.Windows.Forms.PictureBox();
            this.panelTitle = new System.Windows.Forms.Panel();
            this.titleMinimize = new FontAwesome.Sharp.IconButton();
            this.titleZoom = new FontAwesome.Sharp.IconButton();
            this.titleClose = new FontAwesome.Sharp.IconButton();
            this.titleLabel = new System.Windows.Forms.Label();
            this.IconTitleBox = new FontAwesome.Sharp.IconPictureBox();
            this.panelDesktop = new System.Windows.Forms.Panel();
            this.panelMenu.SuspendLayout();
            this.panelLogo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLogo)).BeginInit();
            this.panelTitle.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.IconTitleBox)).BeginInit();
            this.SuspendLayout();
            // 
            // panelMenu
            // 
            this.panelMenu.BackColor = System.Drawing.Color.DimGray;
            this.panelMenu.Controls.Add(this.IconAbout);
            this.panelMenu.Controls.Add(this.IconResources);
            this.panelMenu.Controls.Add(this.IconSymptoms);
            this.panelMenu.Controls.Add(this.IconDashboard);
            this.panelMenu.Controls.Add(this.panelLogo);
            this.panelMenu.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelMenu.Location = new System.Drawing.Point(0, 0);
            this.panelMenu.Name = "panelMenu";
            this.panelMenu.Size = new System.Drawing.Size(220, 845);
            this.panelMenu.TabIndex = 0;
            // 
            // IconAbout
            // 
            this.IconAbout.Dock = System.Windows.Forms.DockStyle.Top;
            this.IconAbout.FlatAppearance.BorderSize = 0;
            this.IconAbout.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.IconAbout.Flip = FontAwesome.Sharp.FlipOrientation.Horizontal;
            this.IconAbout.Font = new System.Drawing.Font("Candara", 10F);
            this.IconAbout.ForeColor = System.Drawing.Color.Gainsboro;
            this.IconAbout.IconChar = FontAwesome.Sharp.IconChar.InfoCircle;
            this.IconAbout.IconColor = System.Drawing.Color.Gainsboro;
            this.IconAbout.IconSize = 32;
            this.IconAbout.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconAbout.Location = new System.Drawing.Point(0, 478);
            this.IconAbout.Name = "IconAbout";
            this.IconAbout.Rotation = 0D;
            this.IconAbout.Size = new System.Drawing.Size(220, 86);
            this.IconAbout.TabIndex = 4;
            this.IconAbout.Text = "About";
            this.IconAbout.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconAbout.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.IconAbout.UseVisualStyleBackColor = true;
            this.IconAbout.Click += new System.EventHandler(this.IconAbout_Click);
            // 
            // IconResources
            // 
            this.IconResources.Dock = System.Windows.Forms.DockStyle.Top;
            this.IconResources.FlatAppearance.BorderSize = 0;
            this.IconResources.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.IconResources.Flip = FontAwesome.Sharp.FlipOrientation.Horizontal;
            this.IconResources.Font = new System.Drawing.Font("Candara", 10F);
            this.IconResources.ForeColor = System.Drawing.Color.Gainsboro;
            this.IconResources.IconChar = FontAwesome.Sharp.IconChar.Bookmark;
            this.IconResources.IconColor = System.Drawing.Color.Gainsboro;
            this.IconResources.IconSize = 32;
            this.IconResources.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconResources.Location = new System.Drawing.Point(0, 392);
            this.IconResources.Name = "IconResources";
            this.IconResources.Rotation = 0D;
            this.IconResources.Size = new System.Drawing.Size(220, 86);
            this.IconResources.TabIndex = 3;
            this.IconResources.Text = "Resources";
            this.IconResources.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconResources.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.IconResources.UseVisualStyleBackColor = true;
            this.IconResources.Click += new System.EventHandler(this.IconResources_Click);
            // 
            // IconSymptoms
            // 
            this.IconSymptoms.Dock = System.Windows.Forms.DockStyle.Top;
            this.IconSymptoms.FlatAppearance.BorderSize = 0;
            this.IconSymptoms.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.IconSymptoms.Flip = FontAwesome.Sharp.FlipOrientation.Horizontal;
            this.IconSymptoms.Font = new System.Drawing.Font("Candara", 10F);
            this.IconSymptoms.ForeColor = System.Drawing.Color.Gainsboro;
            this.IconSymptoms.IconChar = FontAwesome.Sharp.IconChar.Medkit;
            this.IconSymptoms.IconColor = System.Drawing.Color.Gainsboro;
            this.IconSymptoms.IconSize = 32;
            this.IconSymptoms.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconSymptoms.Location = new System.Drawing.Point(0, 306);
            this.IconSymptoms.Name = "IconSymptoms";
            this.IconSymptoms.Rotation = 0D;
            this.IconSymptoms.Size = new System.Drawing.Size(220, 86);
            this.IconSymptoms.TabIndex = 2;
            this.IconSymptoms.Text = "Symptoms";
            this.IconSymptoms.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconSymptoms.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.IconSymptoms.UseVisualStyleBackColor = true;
            this.IconSymptoms.Click += new System.EventHandler(this.IconSymptoms_Click);
            // 
            // IconDashboard
            // 
            this.IconDashboard.Dock = System.Windows.Forms.DockStyle.Top;
            this.IconDashboard.FlatAppearance.BorderSize = 0;
            this.IconDashboard.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.IconDashboard.Flip = FontAwesome.Sharp.FlipOrientation.Horizontal;
            this.IconDashboard.Font = new System.Drawing.Font("Candara", 10F);
            this.IconDashboard.ForeColor = System.Drawing.Color.Gainsboro;
            this.IconDashboard.IconChar = FontAwesome.Sharp.IconChar.Home;
            this.IconDashboard.IconColor = System.Drawing.Color.Gainsboro;
            this.IconDashboard.IconSize = 32;
            this.IconDashboard.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconDashboard.Location = new System.Drawing.Point(0, 220);
            this.IconDashboard.Name = "IconDashboard";
            this.IconDashboard.Rotation = 0D;
            this.IconDashboard.Size = new System.Drawing.Size(220, 86);
            this.IconDashboard.TabIndex = 1;
            this.IconDashboard.Text = "Dashboard";
            this.IconDashboard.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.IconDashboard.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.IconDashboard.UseVisualStyleBackColor = true;
            this.IconDashboard.Click += new System.EventHandler(this.IconDashboard_Click);
            // 
            // panelLogo
            // 
            this.panelLogo.Controls.Add(this.pictureBoxLogo);
            this.panelLogo.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelLogo.Location = new System.Drawing.Point(0, 0);
            this.panelLogo.Name = "panelLogo";
            this.panelLogo.Size = new System.Drawing.Size(220, 220);
            this.panelLogo.TabIndex = 0;
            // 
            // pictureBoxLogo
            // 
            this.pictureBoxLogo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBoxLogo.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxLogo.Image")));
            this.pictureBoxLogo.Location = new System.Drawing.Point(0, 0);
            this.pictureBoxLogo.Name = "pictureBoxLogo";
            this.pictureBoxLogo.Padding = new System.Windows.Forms.Padding(13, 13, 0, 0);
            this.pictureBoxLogo.Size = new System.Drawing.Size(220, 220);
            this.pictureBoxLogo.TabIndex = 0;
            this.pictureBoxLogo.TabStop = false;
            this.pictureBoxLogo.Click += new System.EventHandler(this.pictureBoxLogo_Click);
            // 
            // panelTitle
            // 
            this.panelTitle.BackColor = System.Drawing.Color.DimGray;
            this.panelTitle.Controls.Add(this.titleMinimize);
            this.panelTitle.Controls.Add(this.titleZoom);
            this.panelTitle.Controls.Add(this.titleClose);
            this.panelTitle.Controls.Add(this.titleLabel);
            this.panelTitle.Controls.Add(this.IconTitleBox);
            this.panelTitle.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelTitle.Location = new System.Drawing.Point(220, 0);
            this.panelTitle.Name = "panelTitle";
            this.panelTitle.Size = new System.Drawing.Size(1154, 100);
            this.panelTitle.TabIndex = 1;
            this.panelTitle.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panelTitle_MouseDown);
            // 
            // titleMinimize
            // 
            this.titleMinimize.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.titleMinimize.BackColor = System.Drawing.Color.Transparent;
            this.titleMinimize.FlatAppearance.BorderSize = 0;
            this.titleMinimize.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.titleMinimize.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.titleMinimize.IconChar = FontAwesome.Sharp.IconChar.WindowMinimize;
            this.titleMinimize.IconColor = System.Drawing.Color.WhiteSmoke;
            this.titleMinimize.IconSize = 40;
            this.titleMinimize.Location = new System.Drawing.Point(1001, 12);
            this.titleMinimize.Name = "titleMinimize";
            this.titleMinimize.Rotation = 0D;
            this.titleMinimize.Size = new System.Drawing.Size(33, 31);
            this.titleMinimize.TabIndex = 4;
            this.titleMinimize.UseVisualStyleBackColor = false;
            this.titleMinimize.Click += new System.EventHandler(this.titleMinimize_Click);
            // 
            // titleZoom
            // 
            this.titleZoom.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.titleZoom.BackColor = System.Drawing.Color.Transparent;
            this.titleZoom.FlatAppearance.BorderSize = 0;
            this.titleZoom.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.titleZoom.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.titleZoom.IconChar = FontAwesome.Sharp.IconChar.WindowMaximize;
            this.titleZoom.IconColor = System.Drawing.Color.WhiteSmoke;
            this.titleZoom.IconSize = 40;
            this.titleZoom.Location = new System.Drawing.Point(1055, 12);
            this.titleZoom.Name = "titleZoom";
            this.titleZoom.Rotation = 0D;
            this.titleZoom.Size = new System.Drawing.Size(33, 31);
            this.titleZoom.TabIndex = 3;
            this.titleZoom.UseVisualStyleBackColor = false;
            this.titleZoom.Click += new System.EventHandler(this.titleZoom_Click);
            // 
            // titleClose
            // 
            this.titleClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.titleClose.BackColor = System.Drawing.Color.Transparent;
            this.titleClose.FlatAppearance.BorderSize = 0;
            this.titleClose.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.titleClose.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.titleClose.IconChar = FontAwesome.Sharp.IconChar.WindowClose;
            this.titleClose.IconColor = System.Drawing.Color.WhiteSmoke;
            this.titleClose.IconSize = 40;
            this.titleClose.Location = new System.Drawing.Point(1110, 12);
            this.titleClose.Name = "titleClose";
            this.titleClose.Rotation = 0D;
            this.titleClose.Size = new System.Drawing.Size(33, 31);
            this.titleClose.TabIndex = 2;
            this.titleClose.UseVisualStyleBackColor = false;
            this.titleClose.Click += new System.EventHandler(this.titleClose_Click);
            // 
            // titleLabel
            // 
            this.titleLabel.AutoSize = true;
            this.titleLabel.BackColor = System.Drawing.Color.Transparent;
            this.titleLabel.Font = new System.Drawing.Font("Candara Light", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.titleLabel.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.titleLabel.Location = new System.Drawing.Point(111, 29);
            this.titleLabel.Name = "titleLabel";
            this.titleLabel.Size = new System.Drawing.Size(164, 39);
            this.titleLabel.TabIndex = 1;
            this.titleLabel.Text = "Dashboard";
            // 
            // IconTitleBox
            // 
            this.IconTitleBox.BackColor = System.Drawing.Color.Transparent;
            this.IconTitleBox.Dock = System.Windows.Forms.DockStyle.Left;
            this.IconTitleBox.Flip = FontAwesome.Sharp.FlipOrientation.Horizontal;
            this.IconTitleBox.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.IconTitleBox.IconChar = FontAwesome.Sharp.IconChar.Home;
            this.IconTitleBox.IconColor = System.Drawing.Color.WhiteSmoke;
            this.IconTitleBox.IconSize = 86;
            this.IconTitleBox.Location = new System.Drawing.Point(0, 0);
            this.IconTitleBox.Name = "IconTitleBox";
            this.IconTitleBox.Padding = new System.Windows.Forms.Padding(0, 15, 0, 0);
            this.IconTitleBox.Size = new System.Drawing.Size(86, 100);
            this.IconTitleBox.TabIndex = 0;
            this.IconTitleBox.TabStop = false;
            // 
            // panelDesktop
            // 
            this.panelDesktop.BackColor = System.Drawing.Color.DarkGray;
            this.panelDesktop.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelDesktop.Location = new System.Drawing.Point(220, 100);
            this.panelDesktop.Name = "panelDesktop";
            this.panelDesktop.Size = new System.Drawing.Size(1154, 745);
            this.panelDesktop.TabIndex = 2;
            this.panelDesktop.TabStop = true;
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1374, 845);
            this.Controls.Add(this.panelDesktop);
            this.Controls.Add(this.panelTitle);
            this.Controls.Add(this.panelMenu);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormMain";
            this.Text = "FormMain";
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.panelMenu.ResumeLayout(false);
            this.panelLogo.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLogo)).EndInit();
            this.panelTitle.ResumeLayout(false);
            this.panelTitle.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.IconTitleBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelMenu;
        private FontAwesome.Sharp.IconButton IconAbout;
        private FontAwesome.Sharp.IconButton IconResources;
        private FontAwesome.Sharp.IconButton IconSymptoms;
        private FontAwesome.Sharp.IconButton IconDashboard;
        private System.Windows.Forms.Panel panelLogo;
        private System.Windows.Forms.PictureBox pictureBoxLogo;
        private System.Windows.Forms.Panel panelTitle;
        private FontAwesome.Sharp.IconPictureBox IconTitleBox;
        private System.Windows.Forms.Label titleLabel;
        private System.Windows.Forms.Panel panelDesktop;
        private FontAwesome.Sharp.IconButton titleClose;
        private FontAwesome.Sharp.IconButton titleMinimize;
        private FontAwesome.Sharp.IconButton titleZoom;
    }
}

