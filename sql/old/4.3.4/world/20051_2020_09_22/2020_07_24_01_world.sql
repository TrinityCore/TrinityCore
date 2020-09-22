--
UPDATE creature_template SET flags_extra = flags_extra | 0x00002000 /* CREATURE_FLAG_EXTRA_NO_COMBAT */ WHERE entry IN
(37744 -- ICC Frost Freeze Trap
,37013 -- ICC Rotface Puddle Stalker
);
