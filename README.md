Amero Core staging tree 0.17
===========================

|CI|master|develop|
|-|-|-|
|Gitlab|[![Build Status](https://gitlab.com/ameropay/amero/badges/master/pipeline.svg)](https://gitlab.com/ameropay/amero/-/tree/master)|[![Build Status](https://gitlab.com/ameropay/amero/badges/develop/pipeline.svg)](https://gitlab.com/ameropay/amero/-/tree/develop)|

https://www.amero.org


What is Amero?
-------------

Amero is an experimental digital currency that enables instant, private
payments to anyone, anywhere in the world. Amero uses peer-to-peer technology
to operate with no central authority: managing transactions and issuing money
are carried out collectively by the network. Amero Core is the name of the open
source software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the Amero Core software, see https://www.amero.org/get-amero/.


License
-------

Amero Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is meant to be stable. Development is normally done in separate branches.
[Tags](https://github.com/ameropay/amero/tags) are created to indicate new official,
stable release versions of Amero Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Amero Core's Transifex page](https://www.transifex.com/projects/p/amero/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Translators should also follow the [forum](https://www.amero.org/forum/topic/amero-worldwide-collaboration.88/).
