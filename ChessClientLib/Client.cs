using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using BaseLib;

namespace ChessClientLib
{
    public class Client
    {
        public string host { get; set; }
        public int port { get; set; }

        private int m_index;
        private string m_gameID;
        private TcpClient m_client;
        public void init(string h, int p)
        {
            host = h;
            port = p;
            m_client = new TcpClient();
            m_client.Connect(host, port);
            m_index = 0;
        }
        public void initiateGame()
        {
            Packet pack = new Packet();
            pack.protocol = defines.mProtocol;
            pack.type = MessageType.Start;
            pack.gameId = "";
            pack.packetID = m_index++;
            pack.from = "";
            pack.to = "";
            sendPacket(pack);
            pack = receivePacket();
            m_gameID = pack.gameId;
        }
        public bool move(string from, string to)
        {
            Packet pack = new Packet();
            pack.protocol = defines.mProtocol;
            pack.type = MessageType.Move;
            pack.gameId = m_gameID;
            pack.packetID = m_index;
            pack.from = from;
            pack.to = to;
            sendPacket(pack);
            pack = new Packet();
            pack = receivePacket();

            if (pack.gameId != m_gameID || pack.type != MessageType.ACK || pack.packetID != m_index)
                return false;
            m_index++;
            pack = receivePacket();

            if (pack.gameId == m_gameID && pack.type == MessageType.MoveAccepted)
            {
                m_index++;
                return true;
            }
            else
                return false;
        }

        private Packet receivePacket()
        {
            Packet pack = PacketEncoder.Deserialize(m_client.GetStream());
            if (pack.protocol != defines.mProtocol)
                throw new Exception("Wrong Protocol!!!");
            return pack;
        }
        private void sendPacket(Packet pack)
        {
            PacketEncoder.Serialize(m_client.GetStream(), pack);
        }
    }
}
