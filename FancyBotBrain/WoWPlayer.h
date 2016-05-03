#pragma once

#include "EndSceneManager.h"
#include "WoWInventory.h"
#include "WoWUnit.h"

class WoWPlayer : public WoWUnit
{
public:
    static const uintptr_t DATA_CORPSE_X = 0x24;
    static const uintptr_t DATA_CORPSE_Y = 0x28;
    static const uintptr_t DATA_CORPSE_Z = 0x2C;

    static WoWPlayer Read(void* pObject);

    static void Read(WoWPlayer* pPlayer, void* address);

    void Reset();

    concurrency::task<void> ClickToMove(const Vector3& destination) const;

    concurrency::task<void> InteractWith(const WoWUnit& unit) const;

    concurrency::task<void> Loot(const WoWUnit& unit) const;

    concurrency::task<void> CastSpellByName(const std::string& name) const;

    concurrency::task<void> SetTarget(const WoWUnit& unit) const;

    concurrency::task<void> SetTarget(uint64_t targetGuid) const;

    concurrency::task<void> Turn(const Vector3& position) const;

    concurrency::task<void> SendMovementUpdate(uint32_t opcode) const;

    concurrency::task<void> AutoLoot() const;

    concurrency::task<void> ReleaseSpirit() const;

    concurrency::task<void> ReviveAtCorpse() const;

    bool IsUnitHostile(const WoWUnit& unit) const;

    bool InRangeOf(const Vector3& v, float distance) const;

    bool InRangeOf(const WoWUnit& unit, float distance) const;

    bool IsLooting() const;

    const WoWInventory& GetInventory() const;

    const Position& GetCorpsePosition() const;

    bool IsGhost() const;

private:
    concurrency::task<void> CTM(
        uint64_t targetGuid,
        const Vector3& destination,
        uint32_t flag
    ) const;

protected:
    Position mCorpsePosition;
    WoWInventory mInventory;

    bool mIsLooting;
    bool mIsGhost;
};
