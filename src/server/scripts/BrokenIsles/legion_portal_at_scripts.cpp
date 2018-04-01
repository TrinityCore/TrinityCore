/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Player.h"
#include "ScriptMgr.h"

class at_legion_instance_portal : public AreaTriggerEntityScript
{
public:
    at_legion_instance_portal(const char* name, uint32 mapId, float x, float y, float z, float o) : AreaTriggerEntityScript(name), _tpLocation(mapId, x, y, z, o) {}
    at_legion_instance_portal(const char* name, uint32 worldSafeLocs) : AreaTriggerEntityScript(name)
    {
        WorldSafeLocsEntry const* safeLoc = sWorldSafeLocsStore.LookupEntry(worldSafeLocs);
        ASSERT(safeLoc);
        _tpLocation = WorldLocation(safeLoc->MapID, safeLoc->Loc.X, safeLoc->Loc.Y, safeLoc->Loc.Z, safeLoc->Facing);
    }

    WorldLocation _tpLocation;

    struct at_legion_instance_portalAI : AreaTriggerAI
    {
        at_legion_instance_portalAI(AreaTrigger* areatrigger, WorldLocation tpLocation) : AreaTriggerAI(areatrigger), _tpLocation(tpLocation) { }

        WorldLocation _tpLocation;

        void OnUnitEnter(Unit* unit) override
        {
            if (Player* player = unit->ToPlayer())
                player->TeleportTo(_tpLocation);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_legion_instance_portalAI(areatrigger, _tpLocation);
    }
};

void AddSC_legion_portal_at_scripts()
{
    new at_legion_instance_portal("at_legion_portal_aovh_entrance",    1544,    4581.607f, 3993.067f,  83.48759f, 64.80991f);
    new at_legion_instance_portal("at_legion_portal_aovh_exit",        1220,   -953.0573f, 4333.46f,   740.1838f,  53.1857f);
    new at_legion_instance_portal("at_legion_portal_brh_entrance",     1501,    3484.258f, 7645.708f,  -9.67725f, 191.7235f);
    new at_legion_instance_portal("at_legion_portal_brh_exit",         1220,    3105.248f, 7543.426f,  31.97511f, 221.8234f);
    new at_legion_instance_portal("at_legion_portal_coen_entrance",    1677,     -699.75f,  2528.56f,    332.08f,     1.52f);
    new at_legion_instance_portal("at_legion_portal_coen_exit",        1220,    -425.364f,  2428.47f,   108.398f,  39.4553f);
    new at_legion_instance_portal("at_legion_portal_cos_entrance",     1571,    1016.066f, 3819.521f,  4.816927f, 258.2893f);
    new at_legion_instance_portal("at_legion_portal_cos_exit",         1220,    1022.014f, 3848.595f,  7.826687f, 80.59573f);
    new at_legion_instance_portal("at_legion_portal_hov_entrance",     1477,     3801.21f,  529.078f,   603.332f,  179.395f);
    new at_legion_instance_portal("at_legion_portal_hov_exit",         1220,     2434.39f,  832.011f,   252.923f,  134.077f);
    new at_legion_instance_portal("at_legion_portal_mos_entrance",     1492,    7184.294f, 7318.968f,  23.27296f, 346.8638f);
    new at_legion_instance_portal("at_legion_portal_mos_exit",         1220,    3419.009f, 1988.635f,  15.53604f,  169.902f);
    new at_legion_instance_portal("at_legion_portal_nl_entrance",      1458,     2973.28f,  987.988f,   372.969f,  153.326f);
    new at_legion_instance_portal("at_legion_portal_nl_exit",          1220,     3735.32f,  4182.46f,   892.069f,   351.07f);
    new at_legion_instance_portal("at_legion_portal_rtkara_entrance",  1651,    -11041.3f,-1996.139f,  95.51492f, 122.7583f);
    new at_legion_instance_portal("at_legion_portal_rtkara_exit",      1220,  -11029.900f,-2009.891f, 94.492134f, 5.393635f);
    new at_legion_instance_portal("at_legion_portal_taw_entrance",     1516,     3515.74f,  4805.38f,   590.072f,  177.335f);
    new at_legion_instance_portal("at_legion_portal_taw_exit",         1220,     1168.69f,  4372.91f,   8.35964f,   329.03f);
    new at_legion_instance_portal("at_legion_portal_votw_entrance",    1493,    4184.485f,-762.4045f,  269.4716f, 90.51581f);
    new at_legion_instance_portal("at_legion_portal_votw_exit",        1220,   -1811.731f, 6670.421f,  146.6911f, 148.1312f);
    new at_legion_instance_portal("at_legion_portal_en_entrance",      1520,    1810.125f, 1424.189f,  355.1689f, 339.9064f);
    new at_legion_instance_portal("at_legion_portal_en_exit",          1220,    3588.275f, 6483.405f,  177.9702f, 218.8825f);
    new at_legion_instance_portal("at_legion_portal_tov_entrance",     1648,     3207.87f,  529.281f,   633.148f,    177.3f);
    new at_legion_instance_portal("at_legion_portal_tov_exit",         1220,     2370.78f,  895.832f,   252.924f,  314.302f);
    new at_legion_instance_portal("at_legion_portal_tnh_entrance",     1530,   -149.1892f, 3531.717f,  -253.876f,  314.775f);
    new at_legion_instance_portal("at_legion_portal_tnh_exit",         1220,     1226.82f,   4210.8f,  -66.9462f,   328.54f);
    new at_legion_instance_portal("at_legion_portal_dal_chamber_entrance", 1220,-784.447f, 4418.802f, 602.47973f, 2.443143f);
    new at_legion_instance_portal("at_legion_portal_dal_chamber_exit", 1220, -849.907959f, 4461.175f, 735.66101f, 4.045355f);
    new at_legion_instance_portal("at_legion_portal_helheim_entrance", 1463,    366.2969f, 365.1458f,  28.08436f, 13.97537f);
    new at_legion_instance_portal("at_legion_portal_helheim_exit",     1220, 3641.396973f, 774.1938f, -3.139639f, 2.321205f);
    new at_legion_instance_portal("at_legion_portal_warl_oh_exit",     1220, -796.369568f, 4577.488f, 700.57702f, 4.626544f);
    new at_legion_instance_portal("at_legion_portal_archerus_to_upper",1220, -1469.25f,     1116.78f, 313.74f,    4.165537f);
    new at_legion_instance_portal("at_legion_portal_archerus_to_lower",1220, -1473.09f,     1109.74f, 270.07f,    4.177318f);
}
