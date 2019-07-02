-- Replace two Riverpaw Scouts with Riverpaw Shamans
UPDATE `creature` SET `id`=1065, `modelid`=204, `curhealth`=230, `curmana`=249 WHERE `guid` IN (86657, 86662);
