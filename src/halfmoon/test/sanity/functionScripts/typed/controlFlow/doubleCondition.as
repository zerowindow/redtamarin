// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

function doubleCondition() {
    var x:int = 10;
    var y:int = 30;
    var z:int = 50;

    if ((x != 10) && (y == 30)) {
        z = 25;
    }

    print(x);
}

doubleCondition();

