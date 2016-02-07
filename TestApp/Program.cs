using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using chessAI;

namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            cChessGame test = new cChessGame();
            cMove move = new cMove();
            move.from = "A2";
            move.to = "A3";
            test.move();

        }
    }
}
