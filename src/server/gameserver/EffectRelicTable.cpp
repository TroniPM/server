//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectRelicTable.cpp
// Written by  : elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectRelicTable.h"
#include "Item.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "Player.h"
#include "GCModifyInformation.h"
#include "GCStatusCurrentHP.h"
#include "GCRemoveEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectRelicTable::EffectRelicTable(Item* pItem)
	throw(Error)
{
	__BEGIN_TRY

	m_SafeTime.tv_sec = 0;
	m_SafeTime.tv_usec = 0;

	m_LockTime.tv_sec = 0;
	m_LockTime.tv_usec = 0;

	setTarget(pItem);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectRelicTable::affect()
	throw(Error)
{
	__BEGIN_TRY

	Item* pItem = dynamic_cast<Item*>(m_pTarget);
	affect(pItem);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectRelicTable::affect(Item* pItem)
	throw(Error)
{
	__BEGIN_TRY

	__END_CATCH
}

void EffectRelicTable::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

    Item* pItem = dynamic_cast<Item *>(m_pTarget);
	unaffect(pItem);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectRelicTable::unaffect(Item* pItem)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	/*
	Assert(pItem != NULL);

	// �ɷ�ġ�� ���������� �ǵ����� ���ؼ��� �÷��׸� ����,
	// initAllStat�� �ҷ��� �Ѵ�.
	pItem->removeFlag(Effect::EFFECT_CLASS_HAS_SLAYER_RELIC);

	Zone* pZone = pItem->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pItem->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_HAS_SLAYER_RELIC);
	pZone->broadcastPacket(pItem->getX(), pItem->getY(), &gcRemoveEffect);
	*/
	pItem->removeFlag(getEffectClass());

	__END_DEBUG
	__END_CATCH
}

// SafeTime �� ������ �ʾ����� ������ ���� �� ����.
bool EffectRelicTable::isSafeTime() const
{
	Timeval currentTime;
	getCurrentTime(currentTime);

	return currentTime > m_SafeTime;
}

// LockTime ������ ������ ���� �� ����.
bool EffectRelicTable::isLockTime() const
{
	Timeval currentTime;
	getCurrentTime(currentTime);

	return currentTime < m_LockTime;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectRelicTable::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectRelicTable("
		<< "SafeTime:" << m_SafeTime.tv_sec
		<< ")";
	return msg.toString();

	__END_CATCH
}