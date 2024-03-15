from __future__ import annotations
print(annotations)

# Produkt (Product)
class Chair:
    def sit(self):
        pass

# Konkretne produkty (Concrete Products)
class WoodenChair(Chair):
    def sit(self):
        print("Sitting on a wooden chair.")

class MetalChair(Chair):
    def sit(self):
        print("Sitting on a metal chair.")

# Kreator (Creator)
class ChairFactory:
    def create_chair(self):
        pass

# Konkretne kreatory (Concrete Creators)
class WoodenChairFactory(ChairFactory):
    def create_chair(self):
        return WoodenChair()

class MetalChairFactory(ChairFactory):
    def create_chair(self):
        return MetalChair()

# Przykład użycia
wooden_chair_factory = WoodenChairFactory()
metal_chair_factory = MetalChairFactory()

wooden_chair = wooden_chair_factory.create_chair()
metal_chair = metal_chair_factory.create_chair()

wooden_chair.sit()  # Output: Sitting on a wooden chair.
metal_chair.sit()   # Output: Sitting on a metal chair.
