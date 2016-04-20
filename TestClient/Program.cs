using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using BaseLib;
using System.Text;
using System.Threading.Tasks;
using ChessClientLib;

namespace TestClient
{
    class Program
    {
        static string m_gameID;
        static void Main(string[] args)
        {

            Client cli = new Client();
            cli.init("127.0.0.1", 8080);
            cli.initiateGame();
            bool result = cli.move("A2", "A3");
            

        }
    }
}
