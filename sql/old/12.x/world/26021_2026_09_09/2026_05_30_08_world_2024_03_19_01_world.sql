-- Remove from disables unnedeed LOS spells with TARGET_UNIT_NEARBY_ENTRY
DELETE FROM `disables` WHERE `sourceType`=0 AND `flags`=64 AND `entry` IN (
35113,-- Warp Measurement
36460,-- Ultra Deconsolodation Zapper
45323,-- Returning Vrykul Artifact
51964,-- Tormentor's Incense
58515,-- Burn Corpse
71024);-- Throw Bomb
