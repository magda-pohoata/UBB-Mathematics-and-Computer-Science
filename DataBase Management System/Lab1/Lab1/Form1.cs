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

namespace Lab1
{
    public partial class Form1 : Form
    {
        SqlConnection cs = new SqlConnection("Data Source=DESKTOP-BTE410F\\SQLEXPRESS04;Initial Catalog=Pavilions;Integrated Security=True");
        SqlDataAdapter da = new SqlDataAdapter();
        DataSet ds = new DataSet();
        DataSet ds1 = new DataSet();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            da.SelectCommand = new SqlCommand("SELECT * FROM Pavilions", cs);
            ds.Clear();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];

            
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";
            textBox8.Text = "";
            textBox9.Text = "";
            textBox10.Text = "";
            textBox11.Text = "";
            
        }

        private void button5_Click(object sender, EventArgs e)
        {
            da.SelectCommand = new SqlCommand("SELECT * FROM Climates", cs);
            ds1.Clear();
            da.Fill(ds1);
            dataGridView2.DataSource = ds1.Tables[0];


            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";

            textBox12.Text = "";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            try
            {
                da.SelectCommand = new SqlCommand("SELECT * FROM Pavilions WHERE climate=@z", cs);
                da.SelectCommand.Parameters.Add("@z", SqlDbType.VarChar).Value = textBox12.Text;
                ds.Clear();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //insert
            try
            {
                da.InsertCommand = new SqlCommand("INSERT INTO Climates(climate_zone,annual_precipitation,avg_temperature) VALUES(@z, @ap,@at)", cs);
                da.InsertCommand.Parameters.Add("@z", SqlDbType.VarChar).Value = textBox1.Text;
                da.InsertCommand.Parameters.Add("@ap", SqlDbType.Int).Value =
               Int32.Parse(textBox2.Text);
                da.InsertCommand.Parameters.Add("@at", SqlDbType.Int).Value =
               Int32.Parse(textBox3.Text);
  
                cs.Open();
                da.InsertCommand.ExecuteNonQuery();
                MessageBox.Show("Inserted Succesfull to the Database");
                cs.Close();
                // already inserted - apear in the list
                
                da.SelectCommand = new SqlCommand("SELECT * FROM Climates", cs);
                ds1.Clear();
                da.Fill(ds1);
                dataGridView2.DataSource = ds1.Tables[0];
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }

        }


        private void button3_Click(object sender, EventArgs e)
        {
            //update
            try
            {
                da.UpdateCommand = new SqlCommand("UPDATE Climates set annual_precipitation=@ap,avg_temperature=@at WHERE climate_zone=@z", cs);
                da.UpdateCommand.Parameters.Add("@z", SqlDbType.VarChar).Value = textBox1.Text;
                da.UpdateCommand.Parameters.Add("@ap", SqlDbType.Int).Value =
               Int32.Parse(textBox2.Text);
                da.UpdateCommand.Parameters.Add("@at", SqlDbType.Int).Value =
               Int32.Parse(textBox3.Text);

                cs.Open();
                da.UpdateCommand.ExecuteNonQuery();
                MessageBox.Show("Updated Succesfull to the Database");
                cs.Close();

                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";

                da.SelectCommand = new SqlCommand("SELECT * FROM Climates", cs);
                ds1.Clear();
                da.Fill(ds1);
                dataGridView2.DataSource = ds1.Tables[0];

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //delete
            try
            {
                
                    da.DeleteCommand = new SqlCommand("DELETE FROM Climates WHERE climate_zone=@z", cs);
                    da.DeleteCommand.Parameters.Add("@z", SqlDbType.VarChar).Value = textBox1.Text;
                   

                    cs.Open();
                    da.DeleteCommand.ExecuteNonQuery();
                    MessageBox.Show("Deleted Succesfull from the Database");
                    cs.Close();

                    textBox1.Text = "";
                    textBox2.Text = "";
                    textBox3.Text = "";

                    da.SelectCommand = new SqlCommand("SELECT * FROM Climates", cs);
                    ds1.Clear();
                    da.Fill(ds1);
                    dataGridView2.DataSource = ds1.Tables[0];
                
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }







        private void dataGridView2_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            string r = dataGridView2.SelectedRows[0].Cells[0].Value.ToString();
            textBox1.Text = r;
            r = dataGridView2.SelectedRows[0].Cells[1].Value.ToString();
            textBox2.Text = r;
            r = dataGridView2.SelectedRows[0].Cells[2].Value.ToString();
            textBox3.Text = r;

            r = dataGridView2.SelectedRows[0].Cells[0].Value.ToString();
            textBox12.Text = r;


            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";
            textBox8.Text = "";
            textBox9.Text = "";
            textBox10.Text = "";
            textBox11.Text = "";
        }

        private void dataGridView1_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            string r = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
            textBox4.Text = r;
            r = dataGridView1.SelectedRows[0].Cells[1].Value.ToString();
            textBox5.Text = r;
            r = dataGridView1.SelectedRows[0].Cells[2].Value.ToString();
            textBox6.Text = r;
            r = dataGridView1.SelectedRows[0].Cells[3].Value.ToString();
            textBox7.Text = r;
            r = dataGridView1.SelectedRows[0].Cells[4].Value.ToString();
            textBox8.Text = r;
            r = dataGridView1.SelectedRows[0].Cells[5].Value.ToString();
            textBox9.Text = r;
            r = dataGridView1.SelectedRows[0].Cells[6].Value.ToString();
            textBox10.Text = r;
            r = dataGridView1.SelectedRows[0].Cells[7].Value.ToString();
            textBox11.Text = r;


            textBox12.Text = r;


            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
        }










        private void button7_Click(object sender, EventArgs e)
        {
            //insert
            try
            {
                da.InsertCommand = new SqlCommand("INSERT INTO Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) VALUES(@n, @p,@y,@d,@l,@lf,@c,@z)", cs);
                da.InsertCommand.Parameters.Add("@n", SqlDbType.VarChar).Value = textBox4.Text;
                da.InsertCommand.Parameters.Add("@p", SqlDbType.VarChar).Value = textBox5.Text;
                da.InsertCommand.Parameters.Add("@y", SqlDbType.Int).Value =
               Int32.Parse(textBox6.Text);
                da.InsertCommand.Parameters.Add("@d", SqlDbType.Int).Value =
               Int32.Parse(textBox7.Text);
                da.InsertCommand.Parameters.Add("@l", SqlDbType.VarChar).Value = textBox8.Text;
                da.InsertCommand.Parameters.Add("@lf", SqlDbType.VarChar).Value = textBox9.Text;
                da.InsertCommand.Parameters.Add("@c", SqlDbType.VarChar).Value = textBox10.Text;
                da.InsertCommand.Parameters.Add("@z", SqlDbType.VarChar).Value = textBox11.Text;

                cs.Open();
                da.InsertCommand.ExecuteNonQuery();
                MessageBox.Show("Inserted Succesfull to the Database");
                cs.Close();
                // already inserted - apear in the list

                da.SelectCommand = new SqlCommand("SELECT * FROM Pavilions", cs);
                ds.Clear();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            //update
            try
            {
                da.UpdateCommand = new SqlCommand("UPDATE Pavilions set purpose=@p,year_of_construction=@y,dimension=@d,location_of_pavilion=@l,landform=@lf,country=@c,climate=@z WHERE name_of_pavilion=@n", cs);
                da.UpdateCommand.Parameters.Add("@n", SqlDbType.VarChar).Value = textBox4.Text;
                da.UpdateCommand.Parameters.Add("@p", SqlDbType.VarChar).Value = textBox5.Text;
                da.UpdateCommand.Parameters.Add("@y", SqlDbType.Int).Value =
               Int32.Parse(textBox6.Text);
                da.UpdateCommand.Parameters.Add("@d", SqlDbType.Int).Value =
               Int32.Parse(textBox7.Text);
                da.UpdateCommand.Parameters.Add("@l", SqlDbType.VarChar).Value = textBox8.Text;
                da.UpdateCommand.Parameters.Add("@lf", SqlDbType.VarChar).Value = textBox9.Text;
                da.UpdateCommand.Parameters.Add("@c", SqlDbType.VarChar).Value = textBox10.Text;
                da.UpdateCommand.Parameters.Add("@z", SqlDbType.VarChar).Value = textBox11.Text;

                cs.Open();
                da.UpdateCommand.ExecuteNonQuery();
                MessageBox.Show("Updated Succesfull to the Database");
                cs.Close();


                da.SelectCommand = new SqlCommand("SELECT * FROM Pavilions", cs);
                ds.Clear();
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];

                textBox4.Text = "";
                textBox5.Text = "";
                textBox6.Text = "";
                textBox7.Text = "";
                textBox8.Text = "";
                textBox9.Text = "";
                textBox10.Text = "";
                textBox11.Text = "";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            //delete
            try
            {
                    da.DeleteCommand = new SqlCommand("DELETE FROM Pavilions WHERE name_of_pavilion=@n", cs);
                    da.DeleteCommand.Parameters.Add("@n", SqlDbType.VarChar).Value = textBox4.Text;

                    cs.Open();
                    da.DeleteCommand.ExecuteNonQuery();
                    MessageBox.Show("Deleted Succesfull from the Database");
                    cs.Close();

                    textBox4.Text = "";
                    textBox5.Text = "";
                    textBox6.Text = "";
                    textBox7.Text = "";
                    textBox8.Text = "";
                    textBox9.Text = "";
                    textBox10.Text = "";
                    textBox11.Text = "";

                    da.SelectCommand = new SqlCommand("SELECT * FROM Pavilions", cs);
                    ds.Clear();
                    da.Fill(ds);
                    dataGridView1.DataSource = ds.Tables[0];
                
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                cs.Close();
            }
        }

    }
}
