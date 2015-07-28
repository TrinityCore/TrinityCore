UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82, exp=2, `faction_A`=16, `faction_H`=16, `dmg_multiplier`=7.5, `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=0, `mechanic_immune_mask`=8388624, `ScriptName`='npc_memory' WHERE `entry` IN (
35052,35041,35033,35046,35043,35047,35044,35039,35034,35049,35030,34942,35050,35042,35045,35037,35031,35038,35029,35048,35032,35028,35040,35036,35051);

UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82, exp=2, `faction_A`=16, `faction_H`=16, `dmg_multiplier`=13, `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=0, `mechanic_immune_mask`=8388624 WHERE `entry` IN (
35519,35520,35521,35522,35523,35524,35525,35527,35528,35529,35530,35531,35532,35533,35534,35535,35536,35537,35538,35539,35540,35541,35542,35543,35544);

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=16, `faction_H`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry` IN (35305,35306,35307,35308,35309,35310);
UPDATE `creature_template` SET `dmg_multiplier`=13 WHERE `entry` IN (35306,35308,35310);

UPDATE `creature_template` SET `exp`=2 WHERE `entry` IN (37531,38139,37532,38151);
