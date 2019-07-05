using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace parcial
{
  class Musico
  {
    public string nombre;
    public string apellido;
    public int edad;
    public Orquesta orquesta;
    public Instrumentos instrumentos;
    public Musico()
    {
      this.nombre = "no tiene nombre";
      this.apellido = "no tiene apellido";
      this.edad = 0;

    }

    public Musico(string nombre,string apellido,int edad,Orquesta orquesta,Instrumentos instrumentos)
    {
      this.nombre = nombre;
      this.apellido = apellido;
      this.edad = edad;
      this.orquesta = orquesta;
      this.instrumentos = instrumentos;
    }

    public void Imprimirmusico()
    {
      Console.WriteLine("nombre del musico{0} , apellido del musico{1}, edad del musico{2}",this.nombre,this.apellido,this.edad);

    }
  }
}
