ALTER TABLE `pet_aura`
DROP PRIMARY KEY,
ADD PRIMARY KEY (`guid`,`casterGuid`,`spell`,`effectMask`);
