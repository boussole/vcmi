/*
 * ApplyDamage.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */

#pragma once

#include "Event.h"
#include "SubscriptionRegistry.h"

struct BattleStackAttacked;

namespace battle
{
	class Unit;
}

namespace events
{

class DLL_LINKAGE ApplyDamage : public Event
{
public:
	BattleStackAttacked * pack;

	std::shared_ptr<battle::Unit> target;

	using PreHandler = SubscriptionRegistry<ApplyDamage>::PreHandler;
	using PostHandler = SubscriptionRegistry<ApplyDamage>::PostHandler;
	using BusTag = SubscriptionRegistry<ApplyDamage>::BusTag;

	ApplyDamage(BattleStackAttacked * pack_, std::shared_ptr<battle::Unit> target_);

	void execute(const EventBus * bus) override;

	static SubscriptionRegistry<ApplyDamage> * getRegistry();

	int64_t getDamage();
	void setDamage(int64_t value);

	friend class SubscriptionRegistry<ApplyDamage>;
};

}
