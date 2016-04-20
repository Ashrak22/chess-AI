using BaseLib;
using chessAI;
using System.Net.Sockets;
using System.Net;
using System.Collections.Generic;
using System;

namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            cChessGame test = new cChessGame();


            TcpListener listen = new TcpListener(new IPAddress(new byte[] { 0, 0, 0, 0 }), 8080);
            listen.Start();
            List<TcpClient> clients = new List<TcpClient>();
            Console.WriteLine(" >> Server Started");
            clients.Add(listen.AcceptTcpClient());
            Console.WriteLine(" >> Connection accepted");

            Packet packIncoming;
            Packet packOutgoing = new Packet();

            NetworkStream ns = clients[0].GetStream();
            packIncoming = PacketEncoder.Deserialize(ns);
            if (packIncoming.type == MessageType.Start)
            {
                packOutgoing.protocol = defines.mProtocol;
                packOutgoing.type = MessageType.ACK;
                packOutgoing.gameId = "123aaf15";
                packOutgoing.packetID = packIncoming.packetID;
                packOutgoing.from = "";
                packOutgoing.to = "";
            }
            PacketEncoder.Serialize(ns, packOutgoing);

            packIncoming = PacketEncoder.Deserialize(ns);
            bool testbool = false;

            if (packIncoming.type == MessageType.Move && packIncoming.gameId == "123sghkj15")
            {
                cMove move = new cMove();
                move.from = packIncoming.from;
                move.to = packIncoming.to;
                testbool = test.move(move);
            }
            packOutgoing.protocol = defines.mProtocol;
            packOutgoing.type = MessageType.ACK;
            packOutgoing.gameId = "123sghkj15";
            packOutgoing.packetID = packIncoming.packetID;
            packOutgoing.from = "";
            packOutgoing.to = "";
            PacketEncoder.Serialize(ns, packOutgoing);

            if (testbool)
            {
                packOutgoing.protocol = defines.mProtocol;
                packOutgoing.type = MessageType.MoveAccepted;
                packOutgoing.gameId = "123sghkj15";
                packOutgoing.packetID = packIncoming.packetID + 1;
                packOutgoing.from = "";
                packOutgoing.to = "";
                PacketEncoder.Serialize(ns, packOutgoing);
            }
            else
            {
                packOutgoing.protocol = defines.mProtocol;
                packOutgoing.type = MessageType.MoveDenied;
                packOutgoing.gameId = "123sghkj15";
                packOutgoing.packetID = packIncoming.packetID + 1;
                packOutgoing.from = "";
                packOutgoing.to = "";
                PacketEncoder.Serialize(ns, packOutgoing);
            }
            /* NetworkStream ns = new NetworkStream();
             byte[] bytes = PacketEncoder.Serialize(pack);
             Packet pack2 = PacketEncoder.Deserialize(bytes);*/

        }
    }
}
