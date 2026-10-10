/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "tc_catch2.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DB2Structure.h"
#include "DummyData.h"
#include "Group.h"
#include "Map.h"
#include "MMapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "WorldSession.h"
#include <chrono>

void AddSC_warlock_spell_scripts();

struct WorldSessionTestAccess
{
    static std::unique_ptr<WorldSession> CreateSession()
    {
        auto session = std::make_unique<WorldSession>(1, "fixture", 1, "fixture", nullptr, SEC_PLAYER, 0, 0, "Win", 0min,
            69933, ClientBuild::VariantId{}, LOCALE_enUS, 0, false);
        session->_RBACData = new rbac::RBACData(1, "fixture", 1, SEC_PLAYER);
        return session;
    }
};

namespace
{
struct GatewayData
{
    GatewayData()
    {
        static UnitTestDataLoader::DB2<FlightCapabilityEntry, &FlightCapabilityEntry::ID> flights(sFlightCapabilityStore);
        if (!sFlightCapabilityStore.LookupEntry(1))
        {
            auto loader = flights.Loader();
            loader.Add().ID = 1;
        }
        static UnitTestDataLoader::DB2<MapEntry, &MapEntry::ID> maps(sMapStore);
        if (!sMapStore.LookupEntry(0))
        {
            auto loader = maps.Loader();
            MapEntry& entry = loader.Add();
            entry.ID = 0;
            entry.Directory = "fixture";
            entry.MapName.Str.fill("");
            entry.ParentMapID = -1;
            entry.CosmeticParentMapID = -1;
            MMAP::MMapManager::instance()->InitializeThreadUnsafe({ { 0, {} } });
        }
        static bool const registered = []
        {
            sScriptMgr->SetScriptContext(ScriptMgr::GetNameOfStaticContext());
            AddSC_warlock_spell_scripts();
            sScriptMgr->SwapScriptContext();
            UnitTestDataLoader::LoadGatewayTemplates();
            UnitTestDataLoader::BindGatewayTravelScripts();
            return true;
        }();
        (void)registered;
    }
};

struct GatewayAuraData
{
    GatewayAuraData()
    {
        static UnitTestDataLoader::DB2<SpellNameEntry, &SpellNameEntry::ID> names(sSpellNameStore);
        static UnitTestDataLoader::DB2<SpellEffectEntry, &SpellEffectEntry::ID> effects(sSpellEffectStore);
        static UnitTestDataLoader::DB2<SpellMiscEntry, &SpellMiscEntry::ID> misc(sSpellMiscStore);
        static UnitTestDataLoader::DB2<SpellDurationEntry, &SpellDurationEntry::ID> durations(sSpellDurationStore);
        static bool const initialized = [&]
        {
            auto nameLoader = names.Loader();
            auto effectLoader = effects.Loader();
            auto miscLoader = misc.Loader();
            auto durationLoader = durations.Loader();
            SpellDurationEntry& duration = durationLoader.Add();
            duration.ID = 23;
            duration.Duration = 90000;
            duration.MaxDuration = 90000;
            for (uint32 id : { 113896u, 120729u, 113942u, 1265801u, 1271712u })
            {
                SpellNameEntry& name = nameLoader.Add();
                name.ID = id;
                name.Name.Str.fill("");
                SpellEffectEntry& effect = effectLoader.Add();
                effect.ID = id;
                effect.SpellID = id;
                effect.Effect = SPELL_EFFECT_APPLY_AURA;
                effect.EffectAura = SPELL_AURA_DUMMY;
                effect.ImplicitTarget[0] = TARGET_UNIT_CASTER;
                SpellMiscEntry& spellMisc = miscLoader.Add();
                spellMisc.ID = id;
                spellMisc.SpellID = id;
                spellMisc.DurationIndex = id == 113942 || id == 1271712 ? 23 : 0;
                if (id == 113896 || id == 120729)
                {
                    SpellEffectEntry& cooldown = effectLoader.Add();
                    cooldown.ID = id + 1000000;
                    cooldown.SpellID = id;
                    cooldown.EffectIndex = EFFECT_3;
                    cooldown.Effect = SPELL_EFFECT_TRIGGER_SPELL;
                    cooldown.EffectTriggerSpell = 113942;
                    cooldown.ImplicitTarget[0] = TARGET_UNIT_CASTER;
                }
            }
            return true;
        }();
        (void)initialized;
        sSpellMgr->LoadSpellInfoStore();
    }

    ~GatewayAuraData() { sSpellMgr->UnloadSpellInfoStore(); }
};

struct GatewayEndpoint : TempSummon
{
    GatewayEndpoint(Unit* owner, uint32 entry, uint64 counter) : TempSummon(nullptr, owner, false)
    {
        _Create(ObjectGuid::Create<HighGuid::Creature>(0, entry, counter));
        SetEntry(entry);
    }

    using Creature::SetAI;
};

struct GatewaySpell : Spell
{
    using Spell::Spell;
    using Spell::CallScriptCheckCastHandlers;
    using Spell::CallScriptEffectHandlers;
    using Spell::CallScriptAfterCastHandlers;

    void Attach(char const* name)
    {
        SpellScriptLoader* loader = sScriptMgr->GetSpellScriptLoader(sObjectMgr->GetScriptId(name));
        REQUIRE(loader);
        std::unique_ptr<SpellScript> script{ loader->GetSpellScript() };
        REQUIRE(script);
        script->_Init(name, GetSpellInfo()->Id);
        REQUIRE(script->_Load(this));
        script->_Register();
        m_loadedScripts.push_back(script.release());
    }
};

struct GatewayFixture
{
    struct OfflineLoginPool
    {
        OfflineLoginPool()
        {
            LoginDatabase.SetConnectionInfo("localhost;0;unused;;gateway_fixture", 0, 0);
            REQUIRE(LoginDatabase.Open() == 0);
        }

        ~OfflineLoginPool() { LoginDatabase.Close(); }
    };

    GatewayData data;
    GatewayAuraData spells;
    Map map{ 0, 0, 0, DIFFICULTY_NONE };
    GridRefManager<Creature> grid;
    OfflineLoginPool login;
    std::unique_ptr<WorldSession> ownerSession = WorldSessionTestAccess::CreateSession();
    std::unique_ptr<WorldSession> visitorSession = WorldSessionTestAccess::CreateSession();
    Player owner{ ownerSession.get() };
    Player visitor{ visitorSession.get() };
    std::vector<GatewayEndpoint*> endpoints;

    GatewayFixture()
    {
        UnitTestDataLoader::InitializeEntityGuid(owner, ObjectGuid::Create<HighGuid::Player>(900300));
        UnitTestDataLoader::InitializeEntityGuid(visitor, ObjectGuid::Create<HighGuid::Player>(900301));
        for (Player* player : { &owner, &visitor })
        {
            player->SetMap(&map);
            ObjectAccessor::AddObject(player);
            player->BaseEntity::AddToWorld();
        }
    }

    ~GatewayFixture()
    {
        owner.SetGroup(nullptr);
        visitor.SetGroup(nullptr);
        for (GatewayEndpoint* endpoint : endpoints)
            if (endpoint->IsInWorld())
                endpoint->UnSummon();
        map.RemoveAllObjectsInRemoveList();
        for (Player* player : { &visitor, &owner })
        {
            player->RemoveAllAuras();
            player->BaseEntity::RemoveFromWorld();
            ObjectAccessor::RemoveObject(player);
            player->ResetMap();
        }
    }

    GatewayEndpoint* AddEndpoint(Unit* owner, uint32 entry)
    {
        auto endpoint = new GatewayEndpoint(owner, entry, 900400 + endpoints.size());
        endpoint->SetMap(&map);
        endpoint->AddToGrid(grid);
        map.GetObjectsStore().Insert<Creature>(endpoint);
        endpoint->BaseEntity::AddToWorld();
        endpoint->SetAI(sScriptMgr->GetCreatureAI(endpoint));
        endpoints.push_back(endpoint);
        return endpoint;
    }
};

SpellInfo GatewaySpellInfo()
{
    static SpellNameEntry name = [] { SpellNameEntry value{}; value.ID = 111771; return value; }();
    SpellEffectEntry effect{};
    effect.EffectIndex = EFFECT_1;
    effect.Effect = SPELL_EFFECT_DUMMY;
    return SpellInfo{ &name, DIFFICULTY_NONE, { effect } };
}
}

TEST_CASE("Demonic Gateway replacement preserves other owners and unrelated summons", "[Spells][Warlock][Gateway]")
{
    uint32 firstEntry = GENERATE(59262u, 59271u);
    GatewayFixture fixture;
    GatewayEndpoint* first = fixture.AddEndpoint(&fixture.owner, firstEntry);
    GatewayEndpoint* second = fixture.AddEndpoint(&fixture.owner, firstEntry == 59262 ? 59271 : 59262);
    GatewayEndpoint* foreign = fixture.AddEndpoint(&fixture.visitor, firstEntry);
    GatewayEndpoint* unrelated = fixture.AddEndpoint(&fixture.owner, firstEntry);
    unrelated->SetEntry(999279);
    SpellInfo info = GatewaySpellInfo();
    GatewaySpell spell{ &fixture.owner, &info, TRIGGERED_FULL_MASK };
    spell.m_targets.SetDst(0.0f, 0.0f, 0.0f, 0.0f, 0);
    spell.Attach("spell_warl_demonic_gateway");

    spell.CallScriptEffectHandlers(EFFECT_1, SPELL_EFFECT_HANDLE_LAUNCH);

    CHECK(first->IsDestroyedObject());
    CHECK(second->IsDestroyedObject());
    CHECK_FALSE(foreign->IsDestroyedObject());
    CHECK_FALSE(unrelated->IsDestroyedObject());
    CHECK(foreign->IsInWorld());
    CHECK(unrelated->IsInWorld());
    CHECK(fixture.map.GetObjectsStore().Find<Creature>(first->GetGUID()) == nullptr);
    CHECK(fixture.map.GetObjectsStore().Find<Creature>(second->GetGUID()) == nullptr);
}

TEST_CASE("Demonic Gateway rejects absent and excessive-height destinations", "[Spells][Warlock][Gateway]")
{
    GatewayFixture fixture;
    SpellInfo info = GatewaySpellInfo();
    GatewaySpell spell{ &fixture.owner, &info, TRIGGERED_FULL_MASK };
    spell.Attach("spell_warl_demonic_gateway");

    CHECK(spell.CallScriptCheckCastHandlers() == SPELL_FAILED_BAD_TARGETS);
    spell.m_targets.SetDst(0.0f, 0.0f, 6.01f, 0.0f, 0);
    CHECK(spell.CallScriptCheckCastHandlers() == SPELL_FAILED_NOPATH);
}

TEST_CASE("Demonic Gateway cleans up an endpoint without its partner", "[Spells][Warlock][Gateway]")
{
    GatewayFixture fixture;
    GatewayEndpoint* endpoint = fixture.AddEndpoint(&fixture.owner, 59262);
    REQUIRE(endpoint->AI());

    endpoint->AI()->UpdateAI(999);
    CHECK_FALSE(endpoint->IsDestroyedObject());
    endpoint->AI()->UpdateAI(1);
    CHECK(endpoint->IsDestroyedObject());
}

TEST_CASE("Demonic Gateway accepts its owner and party but rejects unrelated players", "[Spells][Warlock][Gateway]")
{
    GatewayFixture fixture;
    Group group;
    bool sameGroup = GENERATE(false, true);
    if (sameGroup)
    {
        fixture.owner.SetGroup(&group, 0);
        fixture.visitor.SetGroup(&group, 0);
    }
    GatewayEndpoint* source = fixture.AddEndpoint(&fixture.owner, 59262);
    GatewayEndpoint* destination = fixture.AddEndpoint(&fixture.owner, 59271);
    source->AI()->SetGUID(destination->GetGUID(), 0);
    destination->AI()->SetGUID(source->GetGUID(), 0);

    source->AI()->OnSpellClick(&fixture.visitor, false);
    fixture.visitor.m_Events.Update(1);

    CHECK(fixture.visitor.HasAura(113896) == sameGroup);
    CHECK(fixture.visitor.HasAura(113942) == sameGroup);
    source->AI()->OnSpellClick(&fixture.owner, false);
    fixture.owner.m_Events.Update(1);
    CHECK(fixture.owner.HasAura(113896));
    CHECK(fixture.owner.HasAura(113942));
    fixture.owner.SetGroup(nullptr);
    fixture.visitor.SetGroup(nullptr);
}

TEST_CASE("Demonic Gateway blocks reuse until its ordinary cooldown expires", "[Spells][Warlock][Gateway]")
{
    GatewayFixture fixture;
    uint32 entry = GENERATE(59262u, 59271u);
    uint32 travelSpell = entry == 59262 ? 113896 : 120729;
    GatewayEndpoint* source = fixture.AddEndpoint(&fixture.owner, entry);
    GatewayEndpoint* destination = fixture.AddEndpoint(&fixture.owner, entry == 59262 ? 59271 : 59262);
    source->AI()->SetGUID(destination->GetGUID(), 0);
    source->AI()->OnSpellClick(&fixture.owner, false);
    fixture.owner.m_Events.Update(1);
    REQUIRE(fixture.owner.HasAura(travelSpell));
    Aura* cooldown = fixture.owner.GetAura(113942);
    REQUIRE(cooldown);
    fixture.owner.RemoveAurasDueToSpell(travelSpell);

    source->AI()->OnSpellClick(&fixture.owner, false);
    fixture.owner.m_Events.Update(1);

    CHECK_FALSE(fixture.owner.HasAura(travelSpell));
    cooldown->UpdateOwner(90000, &fixture.owner);
    REQUIRE(cooldown->IsExpired());
    cooldown->Remove(AURA_REMOVE_BY_EXPIRE);
    source->AI()->OnSpellClick(&fixture.owner, false);
    fixture.owner.m_Events.Update(1);
    CHECK(fixture.owner.HasAura(travelSpell));
    CHECK(fixture.owner.HasAura(113942));
}

TEST_CASE("Demonic Gateway rejects unavailable destinations and immobile or distant players", "[Spells][Warlock][Gateway]")
{
    GatewayFixture fixture;
    GatewayEndpoint* source = fixture.AddEndpoint(&fixture.owner, 59262);
    GatewayEndpoint* destination = fixture.AddEndpoint(&fixture.owner, 59271);
    source->AI()->SetGUID(destination->GetGUID(), 0);
    uint32 rejection = GENERATE(0u, 1u, 2u, 3u);
    switch (rejection)
    {
        case 0: destination->UnSummon(); break;
        case 1: fixture.owner.SetControlled(true, UNIT_STATE_ROOT); break;
        case 2: fixture.owner.Relocate(6.0f, 0.0f, 0.0f, 0.0f); break;
        case 3: fixture.owner.setDeathState(DEAD); break;
    }

    source->AI()->OnSpellClick(&fixture.owner, false);

    CHECK_FALSE(fixture.owner.HasAura(113896));
    CHECK_FALSE(fixture.owner.HasAura(113942));
    fixture.owner.SetControlled(false, UNIT_STATE_ROOT);
    fixture.owner.setDeathState(ALIVE);
}

TEST_CASE("Demonic Gateway cleans up when its owner is no longer in the world", "[Spells][Warlock][Gateway]")
{
    GatewayFixture fixture;
    GatewayEndpoint* source = fixture.AddEndpoint(&fixture.owner, 59262);
    GatewayEndpoint* destination = fixture.AddEndpoint(&fixture.owner, 59271);
    source->AI()->SetGUID(destination->GetGUID(), 0);
    fixture.owner.BaseEntity::RemoveFromWorld();
    ObjectAccessor::RemoveObject(&fixture.owner);

    source->AI()->UpdateAI(1000);

    CHECK(source->IsDestroyedObject());
}

TEST_CASE("Demonic Gateway replacement scans a populated map without removing unrelated summons", "[Spells][Warlock][Gateway][Performance]")
{
    uint32 count = GENERATE(1000u, 10000u);
    GatewayFixture fixture;
    for (uint32 i = 0; i < count; ++i)
    {
        GatewayEndpoint* endpoint = fixture.AddEndpoint(&fixture.visitor, 59262);
        endpoint->SetEntry(999279);
    }
    GatewayEndpoint* owned = fixture.AddEndpoint(&fixture.owner, 59262);
    SpellInfo info = GatewaySpellInfo();
    GatewaySpell spell{ &fixture.owner, &info, TRIGGERED_FULL_MASK };
    spell.m_targets.SetDst(0.0f, 0.0f, 0.0f, 0.0f, 0);
    spell.Attach("spell_warl_demonic_gateway");
    auto start = std::chrono::steady_clock::now();

    spell.CallScriptEffectHandlers(EFFECT_1, SPELL_EFFECT_HANDLE_LAUNCH);

    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
    INFO("Map scan: " << count << " creatures in " << elapsed.count() << " microseconds (Debug fixture)");
    CHECK(owned->IsDestroyedObject());
    CHECK(fixture.map.GetObjectsStore().Data.Head.size() == count);
}

namespace
{
void ClickGateway(GatewayEndpoint* gateway, Player& player)
{
    gateway->AI()->OnSpellClick(&player, false);
    player.m_Events.Update(1);
}

void ExpireGatewayAura(Player& player, uint32 spellId)
{
    Aura* aura = player.GetAura(spellId);
    REQUIRE(aura);
    aura->UpdateOwner(aura->GetDuration(), &player);
    REQUIRE(aura->IsExpired());
    aura->Remove(AURA_REMOVE_BY_EXPIRE);
}

GatewayEndpoint* CreateGatewayPair(GatewayFixture& fixture, Player& owner, uint32 entry)
{
    GatewayEndpoint* source = fixture.AddEndpoint(&owner, entry);
    GatewayEndpoint* destination = fixture.AddEndpoint(&owner, entry == 59262 ? 59271 : 59262);
    source->AI()->SetGUID(destination->GetGUID(), 0);
    destination->AI()->SetGUID(source->GetGUID(), 0);
    return source;
}
}

TEST_CASE("Frequent Traveler allows one immediate reuse then applies the normal cooldown", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    uint32 entry = GENERATE(59262u, 59271u);
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, entry);
    uint32 travelSpell = entry == 59262 ? 113896 : 120729;
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));

    ClickGateway(source, fixture.owner);

    CHECK(fixture.owner.HasAura(travelSpell));
    CHECK(fixture.owner.HasAura(1271712));
    CHECK_FALSE(fixture.owner.HasAura(113942));
    fixture.owner.RemoveAurasDueToSpell(travelSpell);
    ClickGateway(source, fixture.owner);
    CHECK(fixture.owner.HasAura(travelSpell));
    CHECK(fixture.owner.HasAura(113942));
    CHECK_FALSE(fixture.owner.HasAura(1271712));
    fixture.owner.RemoveAurasDueToSpell(travelSpell);
    ClickGateway(source, fixture.owner);
    CHECK_FALSE(fixture.owner.HasAura(travelSpell));
    ExpireGatewayAura(fixture.owner, 113942);
    ClickGateway(source, fixture.owner);
    CHECK(fixture.owner.HasAura(1271712));
    CHECK_FALSE(fixture.owner.HasAura(113942));
}

TEST_CASE("Frequent Traveler tracks the player across different gateway owners", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    Group group;
    fixture.owner.SetGroup(&group, 0);
    fixture.visitor.SetGroup(&group, 0);
    GatewayEndpoint* own = CreateGatewayPair(fixture, fixture.owner, 59262);
    GatewayEndpoint* other = CreateGatewayPair(fixture, fixture.visitor, 59271);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));

    ClickGateway(own, fixture.owner);
    REQUIRE(fixture.owner.HasAura(1271712));
    ClickGateway(other, fixture.owner);

    CHECK(fixture.owner.HasAura(120729));
    CHECK(fixture.owner.HasAura(113942));
    CHECK_FALSE(fixture.owner.HasAura(1271712));
    CHECK_FALSE(fixture.visitor.HasAura(1271712));
    CHECK_FALSE(fixture.visitor.HasAura(113942));
    fixture.owner.SetGroup(nullptr);
    fixture.visitor.SetGroup(nullptr);
}

TEST_CASE("Frequent Traveler does not grant immediate reuse to an untalented party member", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    Group group;
    fixture.owner.SetGroup(&group, 0);
    fixture.visitor.SetGroup(&group, 0);
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));

    ClickGateway(source, fixture.visitor);

    CHECK(fixture.visitor.HasAura(113896));
    CHECK(fixture.visitor.HasAura(113942));
    CHECK_FALSE(fixture.visitor.HasAura(1271712));
    CHECK_FALSE(fixture.owner.HasAura(1271712));
    fixture.owner.SetGroup(nullptr);
    fixture.visitor.SetGroup(nullptr);
}

TEST_CASE("Demonic Gateway remains usable by the party when its owner dies", "[Spells][Warlock][Gateway]")
{
    GatewayFixture fixture;
    Group group;
    fixture.owner.SetGroup(&group, 0);
    fixture.visitor.SetGroup(&group, 0);
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    fixture.owner.setDeathState(DEAD);

    source->AI()->UpdateAI(1000);
    ClickGateway(source, fixture.visitor);

    CHECK_FALSE(source->IsDestroyedObject());
    CHECK(fixture.visitor.HasAura(113896));
    CHECK(fixture.visitor.HasAura(113942));
    fixture.owner.setDeathState(ALIVE);
    fixture.owner.SetGroup(nullptr);
    fixture.visitor.SetGroup(nullptr);
}

TEST_CASE("Frequent Traveler does not reset when its talent is removed and reapplied", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    bool relearn = GENERATE(false, true);
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));
    ClickGateway(source, fixture.owner);
    REQUIRE(fixture.owner.HasAura(1271712));

    fixture.owner.RemoveAurasDueToSpell(1265801);
    if (relearn)
        REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));
    ClickGateway(source, fixture.owner);

    CHECK(fixture.owner.HasAura(113942));
    CHECK_FALSE(fixture.owner.HasAura(1271712));
}

TEST_CASE("Frequent Traveler becomes available again after its marker expires", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));
    ClickGateway(source, fixture.owner);

    ExpireGatewayAura(fixture.owner, 1271712);
    ClickGateway(source, fixture.owner);

    CHECK(fixture.owner.HasAura(1271712));
    CHECK_FALSE(fixture.owner.HasAura(113942));
}

TEST_CASE("Frequent Traveler falls back to the cooldown when its marker cannot be applied", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));
    fixture.owner.ApplySpellImmune(0, IMMUNITY_ID, 1271712, true);

    ClickGateway(source, fixture.owner);

    CHECK_FALSE(fixture.owner.HasAura(1271712));
    CHECK(fixture.owner.HasAura(113942));
    fixture.owner.ApplySpellImmune(0, IMMUNITY_ID, 1271712, false);
}

TEST_CASE("Frequent Traveler preserves its marker when the cooldown cannot be applied", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));
    ClickGateway(source, fixture.owner);
    REQUIRE(fixture.owner.HasAura(1271712));
    fixture.owner.ApplySpellImmune(0, IMMUNITY_ID, 113942, true);

    ClickGateway(source, fixture.owner);

    CHECK(fixture.owner.HasAura(1271712));
    CHECK_FALSE(fixture.owner.HasAura(113942));
    fixture.owner.ApplySpellImmune(0, IMMUNITY_ID, 113942, false);
    ClickGateway(source, fixture.owner);
    CHECK_FALSE(fixture.owner.HasAura(1271712));
    CHECK(fixture.owner.HasAura(113942));
}

TEST_CASE("Frequent Traveler state survives gateway replacement", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));
    ClickGateway(source, fixture.owner);
    REQUIRE(fixture.owner.HasAura(1271712));
    SpellInfo info = GatewaySpellInfo();
    GatewaySpell spell{ &fixture.owner, &info, TRIGGERED_FULL_MASK };
    spell.m_targets.SetDst(0.0f, 0.0f, 0.0f, 0.0f, 0);
    spell.Attach("spell_warl_demonic_gateway");

    spell.CallScriptEffectHandlers(EFFECT_1, SPELL_EFFECT_HANDLE_LAUNCH);

    CHECK(source->IsDestroyedObject());
    REQUIRE(fixture.owner.HasAura(1271712));
    GatewayEndpoint* replacement = CreateGatewayPair(fixture, fixture.owner, 59271);
    ClickGateway(replacement, fixture.owner);
    CHECK(fixture.owner.HasAura(113942));
    CHECK_FALSE(fixture.owner.HasAura(1271712));
}

TEST_CASE("Frequent Traveler consumes a marker restored through the aura load contract", "[Spells][Warlock][Gateway][FrequentTraveler]")
{
    GatewayFixture fixture;
    GatewayEndpoint* source = CreateGatewayPair(fixture, fixture.owner, 59262);
    REQUIRE(fixture.owner.AddAura(1265801, &fixture.owner));
    ClickGateway(source, fixture.owner);
    Aura* marker = fixture.owner.GetAura(1271712);
    REQUIRE(marker);
    REQUIRE(marker->CanBeSaved());
    marker->UpdateOwner(30000, &fixture.owner);
    int32 maxDuration = marker->GetMaxDuration();
    int32 remaining = marker->GetDuration();
    fixture.owner.RemoveAurasDueToSpell(1271712);
    marker = fixture.owner.AddAura(1271712, &fixture.owner);
    REQUIRE(marker);
    SpellEffectValue amount[] = { 0.0 };
    marker->SetLoadedState(maxDuration, remaining, 0, 0, amount);
    REQUIRE(marker->GetDuration() == remaining);

    ClickGateway(source, fixture.owner);

    CHECK(fixture.owner.HasAura(113942));
    CHECK_FALSE(fixture.owner.HasAura(1271712));
}
