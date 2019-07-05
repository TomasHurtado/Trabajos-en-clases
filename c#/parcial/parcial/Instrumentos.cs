using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace parcial
{
  class Instrumentos
  {
    public string nombre;
    public string tipo;
    public Instrumentos()
    {
      this.nombre = "no tiene";
      this.tipo = "no tiene";
    }
    public Instrumentos(string nombre, string tipo)
    {
      this.nombre = nombre;
      this.tipo = tipo;
    }

    public void ImprimirInstrumento()
    {
      Console.WriteLine("nombre {0} ,tipo {1}", this.nombre,this.tipo);

    }
  }
}
