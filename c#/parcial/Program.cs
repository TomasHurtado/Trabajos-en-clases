using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace parcial
{
  class Program
  {
    static void Main(string[] args)
    {


      Orquesta orquesta1 = new Orquesta();
      orquesta1.ImprimirOrquesta();
      Orquesta orquesta2 = new Orquesta("orquesta2", "lugarS", "sinfonica");
      orquesta2.ImprimirOrquesta();
      Instrumentos instrumentos1 = new Instrumentos();
      instrumentos1.ImprimirInstrumento();

      Musico m1 = new Musico("pepe", "argnto", 23, orquesta2, instrumentos1);
      m1.Imprimirmusico();


      ArrayList listaOrquesta = new ArrayList();
      listaOrquesta.Add(orquesta1);
      listaOrquesta.Add(orquesta2);

      foreach(Orquesta elemento in listaOrquesta)
      {
        elemento.ImprimirOrquesta();
      }
    }
  }
}
