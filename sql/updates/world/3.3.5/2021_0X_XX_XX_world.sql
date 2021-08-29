--
UPDATE creature_template SET flags_extra = flags_extra | 8192 WHERE (flags_extra & 128) > 0;
