
def api_client(api_key):
    
    def get_data(endpoint):
        print(f"Fetching from {endpoint} using key: {api_key}")
    return get_data

# The 'google_service' function now "carries" the key secretly
google_service = api_client("SECRET_123")
google_service("/maps")