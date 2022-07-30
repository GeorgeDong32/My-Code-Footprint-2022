import unittest


class TestAssertions(unittest.TestCase):

    def test_equals(self):
        self.assertEqual("one string", "other string")


if __name__ == '__main__':
    unittest.main()
