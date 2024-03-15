class Bank:
    def __init__(self):
        self.amount = 0
        
    def deposit_money(self, money:int ):
        self.amount += money
        
    def withdraw_money(self, money: int):
        self.amount -= money
        return money
    
class TestBank:
    def test_create_bank(self):
        bank = Bank()
        assert bank.amount == 0
        assert isinstance(bank, Bank)
        
    def test_deposit_money(self):
        # given
        bank = Bank()
        
        # when
        bank.deposit_money(10)
        
        # then
        assert bank.amount == 10
        
    def test_deposit_money_twice(self):
        # given
        bank = Bank()
        
        # when
        bank.deposit_money(10)
        bank.deposit_money(10)
        
        # then
        assert bank.amount == 20
    
    def test_withdraw_money(self):
        # given
        bank = Bank()
        bank.deposit_money(100)
        
        # when
        money = bank.withdraw_money(50)
        
        # then
        assert money == 50
        assert bank.amount == 50