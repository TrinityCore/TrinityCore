UPDATE `creature_template` SET `InhabitType`=7 WHERE `flags_extra` & 128; -- Triggers floating
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|16|8388608 WHERE `type`=6; -- Mobs undeads should be immune to fear and horror
