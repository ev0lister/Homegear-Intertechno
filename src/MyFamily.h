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

#ifndef MYFAMILY_H_
#define MYFAMILY_H_

#include <homegear-base/BaseLib.h>

using namespace BaseLib;

namespace MyFamily
{
class MyCentral;

class MyFamily : public BaseLib::Systems::DeviceFamily
{
public:
	MyFamily(BaseLib::SharedObjects* bl, BaseLib::Systems::IFamilyEventSink* eventHandler);
	virtual ~MyFamily();
	virtual void dispose();

	virtual bool hasPhysicalInterface() { return true; }
	virtual PVariable getPairingInfo();
protected:
	virtual std::shared_ptr<BaseLib::Systems::ICentral> initializeCentral(uint32_t deviceId, int32_t address, std::string serialNumber);
	virtual void createCentral();
};

}

#endif
