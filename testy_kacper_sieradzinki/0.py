import pytest

def is_adult(age: int) -> bool:
    if age >= 18:
        return True
    else:
        return False




def test_is_adult():
    # given
    age = 18
    # when
    result = is_adult(age)

    # then
    assert result
    assert is_adult(18)

def test_is_not_adult():
    assert not is_adult(15)

test_is_adult()



# odpala sie to w konsoli za pomoca modulu pytest
# python -m (m to moduł) pytest 0.py -vvv (very verbose - bardzo gadatliwy)
# pytest wyswietla wiecej informacji niz normalnie
