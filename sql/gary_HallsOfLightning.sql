-- Richtige Windfuryaura fuer Gehaerteter Stahlberserker (http://www.wowhead.com/npc=28579)
UPDATE `creature_addon` SET `auras`= 32910 WHERE `auras`= 61367; -- 61367 wird laut Wowhead von keinem NPC verwendet
UPDATE `creature_template` SET `ScriptName`= 'mob_titanium_siegebreaker' WHERE `entry`= 28961;
UPDATE `creature_template` SET `ScriptName`= 'mob_titanium_thunderer' WHERE `entry`= 28965;
