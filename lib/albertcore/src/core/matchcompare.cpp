// albert - a simple application launcher for linux
// Copyright (C) 2014-2017 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "item.h"
#include "matchcompare.h"
using namespace std;

/** ***************************************************************************/
bool Core::MatchCompare::operator()(const pair<shared_ptr<Item>, uint> &lhs,
                                  const pair<shared_ptr<Item>, uint> &rhs) {
    // Compare urgency then score
    if (lhs.first->urgency() != rhs.first->urgency())
        return lhs.first->urgency() < rhs.first->urgency();
    else if (lhs.second != rhs.second)
        return lhs.second > rhs.second; // Compare match score
    else
        return lhs.first->text().size() < rhs.first->text().size();
}
