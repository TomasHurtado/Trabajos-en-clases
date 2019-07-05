using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace parcial
{
  class Orquesta
  {
    public string nombre;
    public string lugar;
    public string tipo;

    public Orquesta()
    {

      this.nombre = "no tiene";
      this.lugar = "no tiene lugar";
      this.tipo = "no tiene";
    }

    public Orquesta(string nombre, string lugar, string tipo)
    {
      this.nombre =nombre;
      this.lugar = lugar;
      this.tipo = tipo;
    }


    public void ImprimirOrquesta()
    {
      Console.WriteLine("Nombre {0}, Lugar {1}, Tipo{2}", this.nombre, this.lugar, this.tipo);
      Console.ReadLine();
    }

  }
}
