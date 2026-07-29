-- Eversong Woods (Midnight) Fixes

-- Faction fixes
UPDATE creature_template
SET faction = 14
WHERE entry IN (
    250683,250826,250841,255348,250754,250806,255329,250876,250780,
    249574,245927,246145,245940,245941,245591
);

UPDATE creature_template
SET faction = 190
WHERE entry IN (
    254313,246633,246332
);
