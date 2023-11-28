#include <iostream>
#include <string>
#include <vector>

class Item {
public:
    Item(std::string name, std::string for_slot = "None") : name(name), for_slot(for_slot) {}

    std::string GetName() const {
        return name;
    }

    std::string GetSlot() const {
        return for_slot;
    }

private:
    std::string for_slot;
    std::string name;
};

class Equipment {
public:
    Equipment(std::string slotType) : slotType(slotType), equippedItem(nullptr) {}

    void EquipItem(Item item) {
        equippedItem = &item;
    }

    std::string GetSlotType() const {
        return slotType;
    }

    Item* GetEquippedItem() const {
        return equippedItem;
    }

private:
    std::string slotType;
    Item* equippedItem;
};

class Backpack {
public:
    void AddItem(Item* item) {
        items.push_back(item);
        std::cout << "Item added to the backpack: " << item->GetName() << std::endl;
    }

    const std::vector<Item*>& GetItems() const {
        return items;
    }

private:
    std::vector<Item*> items;
};

class Character {
public:
    Character(std::string gender, int age, double height, std::string race)
        : gender(gender), age(age), height(height), race(race) {}

    void AddToBackpack(Item* item) {
        backpack.AddItem(item);
    }

    void EquipItem(Equipment equipment, Item item) {
        if (item.GetSlot() == equipment.GetSlotType()) {
            equipment.EquipItem(item);
            std::cout << item.GetName() << " equipped to " << equipment.GetSlotType() << std::endl;
        }
        else {
            std::cout << item.GetName() << " cant be equipped to " << equipment.GetSlotType() << std::endl;
        }
        
    }

    const Backpack& GetBackpack() const {
        return backpack;
    }

    Equipment GetHeadSlot() const {
        return headSlot;
    }

    Equipment GetHandSlot() const {
        return handSlot;
    }

private:
    std::string gender;
    int age;
    double height;
    std::string race;
    Backpack backpack;
    Equipment headSlot{ "head" };
    Equipment handSlot{ "hand" };
};

int main() {
    Character player("Male", 25, 180.0, "Human");

    Item sword("Sword", "hand");
    Item helmet("Helmet", "head");
    Item potion("Health Potion");

    player.AddToBackpack(&sword);
    player.AddToBackpack(&helmet);
    player.AddToBackpack(&potion);

    player.EquipItem(player.GetHeadSlot(), sword);
    player.EquipItem(player.GetHeadSlot(), helmet);
    player.EquipItem(player.GetHandSlot(), sword);

    std::cout << "Items in the backpack:" << std::endl;
    for (auto item : player.GetBackpack().GetItems()) {
        std::cout << "- " << item->GetName() << std::endl;
    }

    return 0;
}