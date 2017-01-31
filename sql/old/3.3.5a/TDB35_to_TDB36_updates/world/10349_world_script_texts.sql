-- Fix broken string
UPDATE `script_texts` SET `content_default`='%s goes into a berserker rage!' WHERE `entry`=-1000004;

-- Reuse unused
UPDATE `script_texts` SET `content_default`='%s goes into a berserker rage!',`type`=3,`comment`='EMOTE_GENERIC_BERSERK_RAID' WHERE `entry`=-1000005;
