-- Fix rigor mortis being caster upon DK creation which shouldn't
-- Don't excluding just DK class because original value was 0 (all)
UPDATE `playercreateinfo_cast_spell` SET `classMask`=925 WHERE `raceMask`=16 AND `spell`=73523;
