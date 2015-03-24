/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UpdateFetcher_h__
#define UpdateFetcher_h__

#include <DBUpdater.h>

#include <functional>
#include <string>
#include <memory>
#include <vector>

class UpdateFetcher
{
    using Path = boost::filesystem::path;

public:
    UpdateFetcher(Path const& updateDirectory,
        std::function<void(std::string const&)> const& apply,
        std::function<void(Path const& path)> const& applyFile,
        std::function<QueryResult(std::string const&)> const& retrieve);

    uint32 Update(bool const redundancyChecks, bool const allowRehash,
                  bool const archivedRedundancy, int32 const cleanDeadReferencesMaxCount) const;

private:
    enum UpdateMode
    {
        MODE_APPLY,
        MODE_REHASH
    };

    enum State
    {
        RELEASED,
        ARCHIVED
    };

    struct AppliedFileEntry
    {
        std::string const name;

        std::string const hash;

        State const state;

        uint64 const timestamp;

        static inline State StateConvert(std::string const& state)
        {
            return (state == "RELEASED") ? RELEASED : ARCHIVED;
        }

        static inline std::string StateConvert(State const state)
        {
            return (state == RELEASED) ? "RELEASED" : "ARCHIVED";
        }

        std::string GetStateAsString() const
        {
            return StateConvert(state);
        }
    };

    struct DirectoryEntry
    {
        Path const path;

        State const state;
    };

    using LocaleFileEntry = std::pair<Path, State>;

    struct PathCompare
    {
        inline bool operator() (LocaleFileEntry const& left, LocaleFileEntry const& right) const
        {
            return left.first.filename().string() < right.first.filename().string();
        }
    };

    using LocaleFileStorage = std::set<LocaleFileEntry, PathCompare>;
    using HashToFileNameStorage = std::unordered_map<std::string, std::string>;
    using AppliedFileStorage = std::unordered_map<std::string, AppliedFileEntry>;
    using DirectoryStorage = std::vector<UpdateFetcher::DirectoryEntry>;
    using SQLUpdate = std::shared_ptr<std::string>;

    LocaleFileStorage GetFileList() const;
    void FillFileListRecursively(Path const& path, LocaleFileStorage& storage, State const state, uint32 const depth) const;

    DirectoryStorage ReceiveIncludedDirectories() const;
    AppliedFileStorage ReceiveAppliedFiles() const;

    SQLUpdate ReadSQLUpdate(Path const& file) const;
    std::string CalculateHash(SQLUpdate const& query) const;

    uint32 Apply(Path const& path) const;

    void UpdateEntry(AppliedFileEntry const& entry, uint32 const speed = 0) const;
    void RenameEntry(std::string const& from, std::string const& to) const;
    void CleanUp(AppliedFileStorage const& storage) const;

    void UpdateState(std::string const& name, State const state) const;

    Path const _sourceDirectory;

    std::function<void(std::string const&)> const _apply;
    std::function<void(Path const& path)> const _applyFile;
    std::function<QueryResult(std::string const&)> const _retrieve;
};

#endif // UpdateFetcher_h__
