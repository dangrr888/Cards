
################################################################
### README - design for implementing a generic deck of cards ###
################################################################
#
# * Phase 1: Resolve Ambiguity
#
# *  The deck should be completely generic, with each card having a
# *+ unique combination of:
# *    a) denomination
# *    b) suit
# *  The range of denominations and suits are traits of the owning deck.
# *+ Assume each suit has same denominations.
#
# * Phase 2: Define the core classes
#
# ** Card - a class
# ** Deck - a class
# **  Suit and Denomination will be enums provided by client clode to the
# **+ Deck.
#
# * Phase 3: Define class relationships (use UML)
#
# ** A Deck is composed of multiple cards.
# ** A Card cannot exist without a Deck.
# ** There is a 1 to many cardinality between Deck's and Card's.
# **  A Card has a SUIT and a DENOMNATION, a combination of which should be
# **+ unique within a Deck.
#
# * Phase 4: Class responsibilities (use UML)
#
# * SUIT - its an enum
#
# * DENOMINATION - its an enum
#
# * Card
# **  Has a constructor that takes a SUIT and a DENOMINATION -- perhaps a pair
# **+ containing these objects
# ** The SUIT and DENOMINATION of a Card are constant data. So no mutators.
# ** A Card need not be copyable or movable
# ** Accessors for SUIT and DENOMINATION of a Card
# ** Has inserter to pretty print this data
#
# * Deck
# ** Has an id (boost strong type) since some games require >1 deck.
# **  Has constructor that takes an id, which is constant. Has acessor to obtain
# **+ id.
# **  Has initialise private method called by constructor to create and store the
# **+ ((${#suits[*]}*${#denomination[*]})) cards it owns
# ** Has a container that stores its cards. One should not need to copy the deck,
# **+ store the container directly.
# ** Delete the copy semantics of the class, a deck need not be moved nor copied.
# **  The remaining interface is dependent on the game, but there are fundamentals
# **+ that are required of any Deck:
# ***  Shuffle and GetCard to get a random card. Allow a specified number of random
# ***+ cards to be acquired (implemented in terms of singular function).
# *** Card management. Will need to know if a given card has been dealt or not.
# **  Could start to inundate the Card to have flags, but best left to derived classes
# **+ of card. The Deck's container should remain private and accessible only through
# **+ the GetCard(s) interface functions.
# ** Convenience method to get total number of cards.
#
# Phase 5: Testing
#
# * Use google test to write unit tests for Card :
# * Assert no throw on construction of TestCard using TestSuit and TestDenomination.
# * AssertEq value of Suite and denomination of constructed TestCard
#
# * Use google test to write unit tests for Deck :
# * Assert no throw creation of a deck with given TestSuites and TestDenomination.
# * assert size of deck
# * check no throw card with a random seed
