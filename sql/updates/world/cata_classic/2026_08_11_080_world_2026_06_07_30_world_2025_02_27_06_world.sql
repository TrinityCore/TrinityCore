-- Add missing movement flags to The Lich King
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0xC0010166,`StaticFlags4`=0x100000 WHERE `Entry`=29110;
