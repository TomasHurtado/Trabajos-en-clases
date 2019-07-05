using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace calculadora
{
  class Numero
  {
    private double numero;
    public void SetNumero(double numero)
    {
      this.numero = numero;
    }

    public double GetNumero()
    {
      return this.numero;
    }

    private static double ValidNumber(string numero)
    {
      double retorno;
      if(!double.TryParse(numero,out retorno))
      {
        retorno = 0;
      }
      return retorno;
    }

    public Numero(double numero)
    {
      this.numero = numero;

    }

    public Numero(string numero)
    {
      this.numero = Numero.ValidNumber(numero);
    }

    public static double Sumar(Numero n1, Numero n2)
    {
      double retorno;
      retorno = n1.GetNumero() + n2.GetNumero();
      return retorno;
    }
  }
}
