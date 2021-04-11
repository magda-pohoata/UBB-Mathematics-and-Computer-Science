using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace Lab2_v2
{
    public partial class Form1 : Form
    {
        SqlDataAdapter da = new SqlDataAdapter();
        DataSet ds = new DataSet();
        DataSet ds1 = new DataSet();

        string id;

        public Form1()
        {
            InitializeComponent();
            GenerateTextboxes();
        }

        private void dataGridViewParent_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            string con = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;
            SqlConnection cs = new SqlConnection(con);

            id = dataGridViewParent.CurrentRow.Cells[0].Value.ToString();
            try
            {
                string filterChild = ConfigurationManager.AppSettings["filterChild"];
                

                da.SelectCommand = new SqlCommand(filterChild, cs);
                da.SelectCommand.Parameters.Add("@id", SqlDbType.VarChar).Value = id;
                cs.Open();

                ds.Clear();
                da.Fill(ds);
                dataGridViewChild.DataSource = ds.Tables[0];
                cs.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }

        private void dataGridViewChild_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            List<string> ColumnNames = new List<string>(ConfigurationManager.AppSettings["ChildColumnNames"].Split(','));
            id = dataGridViewChild.CurrentRow.Cells[0].Value.ToString();
            int i = 0;
            foreach (string column in ColumnNames)
            {
                TextBox textBox = (TextBox)panel1.Controls[column];
                textBox.Text = dataGridViewChild.CurrentRow.Cells[i].Value.ToString();
                i++;
            }
        }

        

        private void button5_Click(object sender, EventArgs e)
        {
            //SHOW ALL
            string con = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;
            try
            {
                SqlConnection cs = new SqlConnection(con);
                string select = ConfigurationSettings.AppSettings["selectChild"];
                da.SelectCommand = new SqlCommand(select, cs);
                //da.SelectCommand = new SqlCommand("Select * from Client", cs);
                ds.Clear();
                da.Fill(ds);
                dataGridViewChild.DataSource = ds.Tables[0];
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void button4_Click(object sender, EventArgs e)
        {
            //SHOW ALL
            string con = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;
            try
            {
                SqlConnection cs = new SqlConnection(con);
                string select = ConfigurationSettings.AppSettings["selectParent"];
                da.SelectCommand = new SqlCommand(select, cs);

                ds1.Clear();
                da.Fill(ds1);
                dataGridViewParent.DataSource = ds1.Tables[0];
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //insert

            string con = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;

            try
            {
                SqlConnection cs = new SqlConnection(con);
                string ChildTableName = ConfigurationManager.AppSettings["ChildTableName"];
                string ChildColumnNames = ConfigurationManager.AppSettings["ChildColumnNames"];
                string ColumnNamesInsertParameters = ConfigurationManager.AppSettings["ColumnNamesInsertParameters"];
                List<string> ColumnNamesList = new List<string>(ConfigurationManager.AppSettings["ChildColumnNames"].Split(','));
                SqlCommand cmd = new SqlCommand("INSERT INTO " + ChildTableName + " (" + ChildColumnNames + ") VALUES (" + ColumnNamesInsertParameters + ")", cs);
                foreach (string column in ColumnNamesList)
                {
                    TextBox textBox = (TextBox)panel1.Controls[column];
                    cmd.Parameters.AddWithValue("@" + column, textBox.Text);
                }
                cs.Open();
                cmd.ExecuteNonQuery();
                ds.Clear();
                da.Fill(ds);
                MessageBox.Show("Inserted succesfully to the database!");
                cs.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //update

            string con = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;

            try
            {
                SqlConnection cs = new SqlConnection(con);
                string ChildTableName = ConfigurationManager.AppSettings["ChildTableName"];
                string ChildColumnNames = ConfigurationManager.AppSettings["ChildColumnNames"];
                List<string> ColumnNamesList = new List<string>(ConfigurationManager.AppSettings["ChildColumnNames"].Split(','));

                string UpdateQuery = ConfigurationManager.AppSettings["UpdateQuery"];
                SqlCommand cmd = new SqlCommand(UpdateQuery, cs);
                string co = panel1.Controls[0].Text;

                cmd.Parameters.AddWithValue("@id", co);
                foreach (string column in ColumnNamesList)
                {
                    TextBox textbox = (TextBox)panel1.Controls[column];
                    cmd.Parameters.AddWithValue("@" + column, textbox.Text);
                }
                cs.Open();
                cmd.ExecuteNonQuery();
                ds.Clear();
                da.Fill(ds);
                dataGridViewChild.DataSource = ds.Tables[0];
                MessageBox.Show("Updated succesfully!");
                cs.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        private void button3_Click(object sender, EventArgs e)
        {
            //delete
            string con = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;
            SqlConnection cs = new SqlConnection(con);

            try
            {

                List<string> ColumnNamesList = new List<string>(ConfigurationManager.AppSettings["ChildColumnNames"].Split(','));

                string DeleteQuery = ConfigurationManager.AppSettings["DeleteQuery"];
                SqlCommand cmd = new SqlCommand(DeleteQuery, cs);
                //string co = dataGridViewChild.CurrentRow.Cells[0].Value.ToString();
                string co = panel1.Controls[0].Text;

                cmd.Parameters.AddWithValue("@id", co);

                cs.Open();
                cmd.ExecuteNonQuery();
                ds.Clear();
                da.Fill(ds);
                dataGridViewChild.DataSource = ds.Tables[0];
                MessageBox.Show("Deleted succesfully!");
                cs.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }


        private void GenerateTextboxes()
        {
            //GENERATE TEXTBOXES

            try
            {
                List<string> ColumnNames = new List<string>(ConfigurationManager.AppSettings["ChildColumnNames"].Split(','));
                int pointX = 30;
                int pointY = 40;
                int numberOfColumns = Convert.ToInt32(ConfigurationManager.AppSettings["ChildNumberOfColumns"]);
                panel1.Controls.Clear();
                foreach (string column in ColumnNames)
                {
                    TextBox a = new TextBox();
                    Label b = new Label();
                    a.Text = "";
                    b.Text = column;
                    a.Name = column;
                    a.Location = new Point(pointX, pointY);
                    b.Location = new Point(pointX, pointY + 20);
                    a.Visible = true;
                    b.Visible = true;
                    a.Parent = panel1;
                    b.Parent = panel1;
                    panel1.Show();
                    pointX += 115;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                
            }
        }
    }
}
