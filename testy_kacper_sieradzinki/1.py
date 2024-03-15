# testowanie printowanej zawartosci


def get_triangle_field(base: int, height: int) -> float:
    field = 0.5 * base * height
    return print(field)


def test_get_triangle_field(capsys):
    # given
    base = 10
    height = 10

    # when
    get_triangle_field(base, height)
    out, err = capsys.readouterr()

    # then
    assert out == '50.0\n'



# capsys - skrot od capture system

# za pomoca capsys mozna pobierac to co zwraca nasz program
# albo pobierać bledy, ktore zwraca program

    
    
    
