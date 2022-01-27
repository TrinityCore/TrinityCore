-- Important Blackrock Documents should only be lootable from a gameobject
DELETE FROM `creature_loot_template` WHERE `Reference`=0 AND `Item`=12562;
