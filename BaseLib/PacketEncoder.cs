using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaseLib
{
    [Serializable]
    public class PacketEncoder
    {
        public static void Serialize(Stream stream, Packet pack)
        {
            BinaryWriter wr = new BinaryWriter(stream);

            wr.Write(pack.protocol);
            wr.Write((byte)pack.type);
            wr.Write(pack.gameId);
            wr.Write(pack.packetID);
            wr.Write(pack.from);
            wr.Write(pack.to);

        }

        public static Packet Deserialize(Stream stream)
        {
            Packet pack = new Packet();
            BinaryReader br = new BinaryReader(stream);

            pack.protocol = br.ReadByte();
            pack.type = (MessageType)br.ReadByte();
            pack.gameId = br.ReadString();
            pack.packetID = br.ReadInt32();
            pack.from = br.ReadString();
            pack.to = br.ReadString();
            return pack;
        }
    }
}
