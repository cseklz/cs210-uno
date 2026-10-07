#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
	// ---- Part 1: required test harness, do not modify ----
	std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse ==" << std::endl;
	std::unique_ptr<List<int>> nums = makeList<int>();
	nums->addFront(new int(10));
	nums->addFront(new int(20));
	nums->addFront(new int(30));
	nums->print();
	nums->addAnywhere(1, new int(99));
	nums->print();
	nums->deleteAnywhere(2);
	nums->print();
	nums->reverse();
	nums->print();
	std::cout << std::endl << "== List<int>: concat ==" << std::endl;
	std::unique_ptr<List<int>> more = makeList<int>();
	more->addFront(new int(2));
	more->addFront(new int(1));
	more->print();
	nums->concat(more.get());
	nums->print();
	more->print();

	// ---- Part 2: your Uno scene goes below ----
	std::cout << std::endl << "== Part 2: Uno Game Scene ==" << std::endl;

	// 1. A table forms, three or four players join the turn order with starting hands.
	std::cout << "\n--- Step 1: Table 1 forms with four players ---" << std::endl;
	std::unique_ptr<List<Player>> players = makeList<Player>();

	auto* julie = new Player(1, "Julie");
	julie->dealCard(new Card("Blue", "3"));
	julie->dealCard(new Card("Red", "5"));

	auto* kai = new Player(2, "Kai");
	kai->dealCard(new Card("Green", "2"));
	kai->dealCard(new Card("Red", "Reverse"));

	auto* angel = new Player(3, "Angel");
	angel->dealCard(new Card("Yellow", "7"));
	angel->dealCard(new Card("Wild", "Win"));

	auto* luca = new Player(4, "Luca");
	luca->dealCard(new Card("Yellow", "9"));
	luca->dealCard(new Card("Green", "Skip"));

	players->addFront(julie);
	players->addFront(kai);
	players->addFront(angel);
	players->addFront(luca);
	std::cout << "Current turn order: ";
	players->print();

	// 2. A new player pulls up a chair and joins mid-order, not at the front, using addAnywhere.
	std::cout << "\n--- Step 2: Adele joins mid-order at position 2 ---" << std::endl;
	auto* adele = new Player(5, "Adele");
	adele->dealCard(new Card("Red", "1"));
	adele->dealCard(new Card("Blue", "DrawTwo"));
	players->addAnywhere(2, adele);
	std::cout << "Turn order after Adele joins: ";
	players->print();

	// 3. Someone plays a Reverse card, using reverse, and turn order is printed before and after.
	std::cout << "\n--- Step 3: Kai plays a Reverse card! ---" << std::endl;
	std::cout << "Kai plays from hand: " << *kai->getHand()->peek() << "!" << std::endl;
	kai->getHand()->pop();
	std::cout << "Turn order before reverse: ";
	players->print();
	players->reverse();
	std::cout << "Turn order after reverse:  ";
	players->print();

	// 4. A player runs out of cards and steps away from a position that isn't the front, using deleteAnywhere.
	std::cout << "\n--- Step 4: Angel plays his last card and wins! Steps away from position 2 ---" << std::endl;
	std::cout << "Angel plays from hand: " << *angel->getHand()->peek() << "!" << std::endl;
	angel->getHand()->pop();
	std::cout << "Turn order before winner leaves: ";
	players->print();
	players->deleteAnywhere(2);
	std::cout << "Turn order after winner leaves:  ";
	players->print();

	// 5. A second table, built separately, merges into the first using concat.
	std::cout << "\n--- Step 5: Table 2 finishes early and merges into Table 1 ---" << std::endl;
	std::unique_ptr<List<Player>> newPlayers = makeList<Player>();
	auto* steph = new Player(13, "Steph");
	steph->dealCard(new Card("Blue", "0"));
	auto* anna = new Player(14, "Anna");
	anna->dealCard(new Card("Green", "7"));
	auto* dane = new Player(15, "Dane");
	dane->dealCard(new Card("Yellow", "3"));
	auto* robert = new Player(16, "Robert");
	robert->dealCard(new Card("Red", "8"));

	newPlayers->addFront(steph);
	newPlayers->addFront(anna);
	newPlayers->addFront(dane);
	newPlayers->addFront(robert);

	std::cout << "Table 1 before merge: ";
	players->print();
	std::cout << "Table 2 before merge: ";
	newPlayers->print();

	players->concat(newPlayers.get());

	std::cout << "Table 1 after merge: ";
	players->print();
	std::cout << "Table 2 after merge (should be empty): ";
	newPlayers->print();

	return 0;
}