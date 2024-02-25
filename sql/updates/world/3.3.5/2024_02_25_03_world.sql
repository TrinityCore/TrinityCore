-- Update gossip text for Darnassus Sentinel for Mage & Paladin directions
SET @text="You will find a pair of draenei conversing with Tyrande Whisperwind in the upper level of The Temple of the Moon.$B$BThey will know how to help you.";
UPDATE `npc_text` SET `text0_0`=@text, `text0_1`=@text,`BroadcastTextID0`=0, `VerifiedBuild`=49705 WHERE `ID`=15906;
