using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace calculadora
{
  public partial class Form1 : Form
  {
    public Form1()
    {
      InitializeComponent();
    }

    private void Suma_Click(object sender, EventArgs e)
    {
      string numero1 = this.textBox1.Text;
      string numero2 = this.textBox2.Text;
      Numero n1 = new Numero(numero1);
      Numero n2 = new Numero(numero2);
      double resultado = Numero.Sumar(n1, n2);
      this.textBox3.Text = resultado.ToString();
    }
  }
}
