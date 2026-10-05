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

	std::cout << "\n--- Step 1: Table 1 forms with four players ---" << std::endl;
	std::unique_ptr<List<Player>> players = makeList<Player>();
	players->addFront(new Player(1, "Julie"));
	players->addFront(new Player(2, "Kai"));
	players->addFront(new Player(3, "Angel"));
	players->addFront(new Player(4, "Luca"));
	std::cout << "Current turn order: ";
	players->print();

	// 2. A new player pulls up a chair and joins mid-order, not at the front, using addAnywhere.
	std::cout << "\n--- Step 2: Adele joins mid-order at position 2 ---" << std::endl;
	players->addAnywhere(2, new Player(5, "Adele"));
	std::cout << "Turn order after Adele joins: ";
	players->print();

	// 3. Someone plays a Reverse card, using reverse, and you print the turn order before and after.
	std::cout << "\n--- Step 3: Kai plays a Reverse card! ---" << std::endl;
	std::cout << "Turn order before reverse: ";
	players->print();
	players->reverse();
	std::cout << "Turn order after reverse:  ";
	players->print();

	// 4. A player runs out of cards and steps away from a position that isn't the front, using deleteAnywhere.
	std::cout << "\n--- Step 4: Angel plays his last card and wins! Steps away from position 2 ---" << std::endl;
	std::cout << "Turn order before winner leaves: ";
	players->print();
	players->deleteAnywhere(2);
	std::cout << "Turn order after winner leaves:  ";
	players->print();

	// 5. A second table, built separately, merges into the first using concat.
	std::cout << "\n--- Step 5: Table 2 finishes early and merges into Table 1 ---" << std::endl;
	std::unique_ptr<List<Player>> newPlayers = makeList<Player>();
	newPlayers->addFront(new Player(13, "Steph"));
	newPlayers->addFront(new Player(14, "Anna"));
	newPlayers->addFront(new Player(15, "Dane"));
	newPlayers->addFront(new Player(16, "Robert"));

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