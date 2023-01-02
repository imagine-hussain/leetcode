from typing import Dict, List, Tuple


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        email_to_id_map: Dict[str, Tuple[int, str]] = {}
        for account in accounts:
            self.merge(account, email_to_id_map)

        id_to_email_map: Dict[int, List[str]] = {}
        for email, acc in email_to_id_map:
            acc_id, name = acc
            if not acc_id in id_to_email_map:
                id_to_email_map[acc_id] = [name]
            id_to_email_map[acc_id].append(email)

        return [
                self.format_return(acc)
                for acc in id_to_email_map.values()
            ]

    def format_retur(data: List[str]) -> List[str]:
        name, *emails = data
        return name + sorted(emails)

    def merge(self, account: List[str], email_to_id_map) -> None:
        name, *emails = account
        acc_id = self.fetch_id_from_map(emails, email_to_id_map)
        for email in emails:
            email_to_id_map[email] = (acc_id, name)

    def fetch_id_from_map(self, emails: List[str], email_map: Dict[str, Tuple[int, str]]) -> int:
        for email in emails:
            if email in email_map.values():
                return email_map[0]
        return gen_id()


ID_COUNT: int = 0
def gen_id() -> int:
    global ID_COUNT
    ID_COUNT += 1
    return ID_COUNT


