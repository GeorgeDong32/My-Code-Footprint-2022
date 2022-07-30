import unittest


def str_to_bool(value):
    true_values = ['y', 'yes']
    false_values = ['no', 'n']
    try:
        value = value.lower()
    except AttributeError:
        raise AttributeError(f"{value} must be of type string")
    if value in true_values:
        return True
    if value in false_values:
        return False


class TestStrToBool(unittest.TestCase):

    def test_y_is_true(self):
        result = str_to_bool('y')
        self.assertTrue(result)

    def test_yes_is_true(self):
        result = str_to_bool('Yes')  # 错误，Yes不属于真值列表中的一个
        self.assertTrue(result)

    def test_invalid_input(self):
        with self.assertRaises(AttributeError):
            str_to_bool(1)


if __name__ == '__main__':
    unittest.main()
