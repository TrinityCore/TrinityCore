ALTER TABLE npc_vendor DROP PRIMARY KEY,
ADD PRIMARY KEY (`entry`,`item`,`ExtendedCost`);
