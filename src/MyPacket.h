/* Copyright 2013-2019 Homegear GmbH
 *
 * Homegear is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Homegear is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Homegear.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */

#ifndef MYPACKET_H_
#define MYPACKET_H_

#include <homegear-base/BaseLib.h>

namespace MyFamily
{

class MyPacket : public BaseLib::Systems::Packet
{
    public:
        MyPacket();
        MyPacket(std::string& rawPacket);
        MyPacket(int32_t senderAddress, std::string& payload);
        virtual ~MyPacket();

        int32_t getChannel() { return _channel; }
        void setChannel(int32_t value) { _channel = value; }
        std::string getPayload() { return _payload; }
        void setPacket(std::string& value) { _packet = value; }
        std::string hexString();
        uint8_t getRssi() { return _rssi; }
    protected:
        std::string _packet;
        std::string _payload;
        int32_t _channel = -1;
        uint8_t _rssi = 0;

        uint8_t parseNibble(char nibble);
        std::string parseNibbleString(char nibble);
        uint8_t parseNibbleSmall(char nibble);
        std::string parseNibbleStringSmall(char nibble);
};

typedef std::shared_ptr<MyPacket> PMyPacket;

}
#endif
