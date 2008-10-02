ALTER TABLE corpse
  ADD KEY idx_type (corpse_type);

UPDATE corpse
  SET corpse_type = 1 WHERE corpse_type = 2;
