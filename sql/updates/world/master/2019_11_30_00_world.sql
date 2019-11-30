UPDATE creature_template SET unit_flags3 = unit_flags | 8192 WHERE (unit_flags2 & 1) != 0;
